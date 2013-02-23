module MiniLangEvaluator where

import MiniLangSyntax
import Data.List (findIndex)

-- Expression evaluator
eval :: Env -> Expr -> Expr
eval _ (IntLit i) = IntLit i
eval _ (BoolLit b) = BoolLit b
eval env (Var n) = lookupVar env n
eval env (BinOp op a b) = primEval op (eval env a) (eval env b)

-- Env is an association list from variable names to expressions
-- Expressions in the environment are assumed to always be values 
type VarName = String
type Env = [(VarName, Expr)]

-- Check if a variable exists in an environment
isVarDefined :: Env -> VarName -> Bool
isVarDefined env n = n `elem` map fst env

-- Add a new variable to the environment
newVar :: Env -> VarName -> Expr -> Env
newVar env n e = (n, e):env

-- Assign to a variable.
-- If variable exists, replace its value. If it doesn't, add
-- the variable binding. Note, this implementaiton is very 
-- inefficient
assignVar :: Env -> VarName -> Expr -> Env
assignVar env n e = 
    if isVarDefined env n then
        map (\(n', e') -> if n == n' then (n, e) else (n', e')) env
    else
        newVar env n e

-- Look up the value of a variable from the environment
-- If the variable is not found, crash
lookupVar :: Env -> VarName -> Expr
lookupVar ((n, v):_) m | n == m = v
lookupVar (_:env) m = lookupVar env m
lookupVar [] m = error $ "Unknown variable " ++ m

-- interface for assignVar
declareVar :: Env -> VarName -> Expr -> Env
declareVar env n e =
    if isVarDefined env n then error $ "Variable already exists " ++ n
    else newVar env n e

-- Execute statement
-- Statments can affect the environment, hence return a new
-- environment
exec :: Env -> Stmt -> Env
exec env (While c b) = 
	if eval env c == BoolLit True
					then do
							let envNext = foldl exec env b
							exec envNext (While c b)
					else env
exec env (Block b) = exitBlock $ foldl exec (enterBlock env) b
exec env Skip = env
exec env (If c t e) = 
    exec env ( if eval env c == BoolLit True then t else e ) 
exec env (Assignment v e) = assignVar env v (eval env e)
exec env (AssignmentVar d) = declareVar env d (Undefined)
exec env (AssignmentVarInt v e) = declareVar env v (eval env e)
-- SVGL figgred out this stuff

-- enter a block by putting ("$",Undefined) in the env stack
enterBlock :: Env -> Env
enterBlock env = declareVar env "$" (Undefined)

-- exit a block by deleting thru the character we put in
exitBlock :: Env -> Env
exitBlock env = case findIndex (==("$", (Undefined))) env of
                  Just n -> drop (n + 1) env
                  Nothing -> error $ "Can't find the ($,Undefined)"
-- SVGL added Block fcns

-- Running the program means executing each of its statements.
-- The frist statement is executed in the empty environment,
-- the next statement in tne environment resulting from the first
-- statement, and so on
-- The expression of the program is evaluated in the environment
-- produced by the last statement
run :: Program -> Expr
run (Program statements e) =
    eval (foldl exec [] statements) e




