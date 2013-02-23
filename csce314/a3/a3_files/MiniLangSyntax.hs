module MiniLangSyntax where

-- This it the abstract syntax of our small language
-- First the expressions in the language

data Expr = IntLit Int 
          | BoolLit Bool
          | BinOp Op Expr Expr
          | Undefined
          | Var String
            deriving Eq

-- The different kinds of operations that are supported
data Op = OpPlus | OpMinus | OpMultiplies | OpDivides | OpEqual | OpNotEqual | OpGreater | OpLesser | OpGreaterEq | OpLesserEq
        deriving Eq
-- GL added OpDivides, OpGreater, OpLesser, OpGreaterEq, OpLesserEq

-- Statements of our language
data Stmt = Skip 
          | If Expr Stmt Stmt
          | Assignment String Expr
          | AssignmentVar String
          | AssignmentVarInt String Expr
		  | Block [Stmt]
		  | While Expr [Stmt]

-- A program is a list of statements, followed by a single expression
data Program = Program [Stmt] Expr

instance PP Program where
  pp _ (Program ss e) =
      concatMap (pp 0) ss ++ show e

-- The primitive functions of our language
primEval OpPlus (IntLit i) (IntLit j) = IntLit $ i + j
primEval OpMinus (IntLit i) (IntLit j) = IntLit $ i - j
primEval OpMultiplies (IntLit i) (IntLit j) = IntLit $ i * j
primEval OpEqual (IntLit i) (IntLit j) = BoolLit $ i == j
primEval OpEqual (BoolLit i) (BoolLit j) = BoolLit $ i == j
primEval OpNotEqual (IntLit i) (IntLit j) = BoolLit $ i /= j
primEval OpNotEqual (BoolLit i) (BoolLit j) = BoolLit $ i /= j

primEval OpDivides (IntLit i) (IntLit j) = IntLit $ i `quot` j
primEval OpGreater (IntLit i) (IntLit j)  		| i > j				= BoolLit $ True
												| otherwise			= BoolLit $ False
primEval OpLesser (IntLit i) (IntLit j)  		| i < j				= BoolLit $ True
												| otherwise			= BoolLit $ False
primEval OpGreaterEq (IntLit i) (IntLit j)  	| i > j				= BoolLit $ True
												| i == j			= BoolLit $ True
												| otherwise			= BoolLit $ False
primEval OpLesserEq (IntLit i) (IntLit j)  		| i < j				= BoolLit $ True
												| i == j 			= BoolLit $ True
												| otherwise			= BoolLit $ False
-- GL added OpDivides here, `quot` is integer division (no decimal), OpDivides, OpGreater, OpLesser, OpGreaterEq, OpLesserEq

primEval x l r = error $ 
                 "ICE: no definition for primitive operation: " ++ show x ++ " " ++ show l ++ " " ++ show r

-- A helper function to turn a string representation to the opcode, 
-- to be used in the parser
stringToOp :: String -> Op
stringToOp "+" = OpPlus
stringToOp "-" = OpMinus
stringToOp "*" = OpMultiplies
stringToOp "/" = OpDivides
stringToOp "==" = OpEqual
stringToOp "<>" = OpNotEqual
stringToOp ">" = OpGreater
stringToOp "<" = OpLesser
stringToOp ">=" = OpGreaterEq
stringToOp "<=" = OpLesserEq


indent :: Int -> String
indent n = replicate n ' '

-- A tiny bit of smarts on how to lay out code, so that it is less tedious to read
class PP a where 
  pp :: Int -> a -> String

instance PP Stmt where
  pp ind (Block c) =  
						"{\n" ++ 
						concatMap (pp ind) c ++ 
						"}\n"
  pp ind (If c t e) = indent ind ++ 
                      "if (" ++ show c ++ ") \n" ++ 
                      pp (ind + 2) t ++
                      indent ind ++ "else\n" ++
                      pp (ind + 2) e
  pp ind (Skip) = indent ind ++ ";\n"
  pp ind (Assignment v e) = indent ind ++ v ++ "=" ++ show e ++ ";\n"
  pp ind (AssignmentVar v) = indent ind ++ v ++ "=undefined" ++ ";\n"
  pp ind (AssignmentVarInt v e) = indent ind ++ v ++ "=" ++ show e ++ ";\n"
  pp ind (While c b) = indent ind ++ "while " ++ addParens (show c) ++ "\n" ++ concatMap (pp ind) b
  -- cannot pass as block, have to use [Stmt] b/c in Data def
 -- SV added Block

instance Show Op where
         show OpPlus = "+"
         show OpMinus = "-"
         show OpMultiplies = "*"
         show OpDivides = "/"
         show OpEqual = "=="
         show OpNotEqual = "<>"
         show OpGreater = ">"
         show OpLesser = "<"
         show OpGreaterEq = ">="
         show OpLesserEq = "<="

instance Show Expr where
    show (IntLit i) = show i
    show (BoolLit b) = show b
    show (Var x) = x
    show (BinOp op a b) = addParens $ show a ++ show op ++ show b

addParens s = "(" ++ s ++ ")"
