module MiniLangParser (parse, start) where 

import Prelude hiding (fail)
import MiniLangSyntax
import ParserCombinators

-- Parsers for the expression language
start :: Parser Program
start = space >> program

comment = string "--" >> many (sat (/= '\n')) >> space >> return ()

-- program is many statements followed by an expression
program = many stmt >>= \s -> 
          expr >>= \e ->
          return $ Program s e

----------------
-- Statements --
----------------

-- It is important that assignment is tried last
-- We want that the alternatives tried first fail at the first token, without consuming input
stmt = skip +++ ifstmt +++ while +++ block +++ assignmentVarInstantiation +++ assignmentVar +++ assignmentInstantiation
-- GL added +++ block
-- SVGL added assignments

skip = symbol ";" >> return Skip

ifstmt = symbol "if" >>
         parens expr >>= \c ->
         stmt >>= \t ->
         symbol "else" >>
         stmt >>= \e ->
         return $ If c t e
		 
block = symbol "{" >>
		many stmt >>= \c ->
		symbol "}" >>
		return (Block c)
-- SV added block

while = symbol "while" >> 
		parens expr >>= \c ->
		many stmt >>= \b ->
		return (While c b)
-- GL added while
         
-- make sure assignment is tried last
assignmentVarInstantiation = symbol "var" >>
			 token identifier >>= \v ->
             symbol "=" >>
             expr >>= \e ->
             symbol ";" >> 
             return (AssignmentVarInt v e) 
assignmentVar = symbol "var" >>
			 token identifier >>= \v ->
             return (AssignmentVar v) 
assignmentInstantiation = token identifier >>= \v ->
             symbol "=" >>
             expr >>= \e ->
             symbol ";" >> 
             return (Assignment v e)
			 


-----------------
-- Expressions --
-----------------

expr = composite +++ atomic

atomic = literal +++ varRef +++ parens expr

literal = intLiteral +++ boolLiteral

intLiteral = token nat >>= \i -> return $ IntLit i

boolLiteral = strue +++ sfalse

strue = symbol "true" >> return (BoolLit True)
sfalse = symbol "false" >> return (BoolLit False)

varRef = token identifier >>= \n -> return (Var n)

composite = comparison >>= \left ->
            compositeX left

compositeX left
    = ((symbol "==" +++ symbol "<>") >>= \op -> 
           comparison >>= \right -> 
           compositeX $ BinOp (stringToOp op) left right)
      +++
      return left
      
-- GL changed summation to comparison in composite

comparison = summation >>= \left -> comparisonX left

comparisonX left = 
	((symbol "<=" +++ symbol ">=" +++ symbol "<" +++ symbol ">") >>= \op ->
		summation >>= \right ->
		comparisonX $ BinOp (stringToOp op) left right)
	+++
	return left
	
-- GL added comparison and comparisonX

summation = term >>= \left -> 
            summationX left

summationX left = 
    ((symbol "+" +++ symbol "-") >>= \op -> 
         term >>= \right ->
         summationX $ BinOp (stringToOp op) left right)
    +++ 
    return left

term = atomic >>= \left -> 
       termX left

termX left = 
    (symbol "*" +++ symbol "/" >>= \op ->
         atomic >>= \right ->
         termX $ BinOp (stringToOp op) left right)
    +++
    return left
