

module MiniLangTyping where

import MiniLangSyntax
import WSE

import Control.Monad (when)

import Data.List (nub, (\\))

import Environment

type Message = String
type TypingM a = WSE Message (Env VarName Ty) Message a

-- The "typing monad"
-- W: the log is a list of type error messages
--   tell function adds to the log
-- S: the state is an association list mapping variable names to types
--   get, put, and modify functions access and modify the environment
-- E: Error type is String
--   throwError and catchError deal with errors 
--   (none are thrown in the evaluator)


-- add a type error to the error message log
tellTE :: Message -> TypingM ()
tellTE s = tell $ "Type error: " ++ s

-- throw a type error 
throwTE :: Message -> TypingM a
throwTE s = throwError $ "Type error: " ++ s

--------------------------
-- Type check a program --
--------------------------

typeProg :: Program -> IO Ty
typeProg (Program ss) = do
  let checker = 
          catchError ( mapM_ typeOK ss >> 
                       typeOf (FunCall "main" [])) 
            (\s -> tell s >> return undefined)
            -- if type checking fails, handle the error
            -- by adding it to the error log

  case runWSE checker emptyEnv of
    (Right ty, _, []) -> return ty
    (_, _, msgs) | not (null msgs) 
                     -> do 
                     mapM_ putStrLn msgs
                     fail "Type-checking failed"
                 | otherwise -> fail "ICE"
                     
------------------------
-- Type an expression --
------------------------

typeOf :: Expr -> TypingM Ty

typeOf (IntLit _) = return TyInt

typeOf (BoolLit _) = return TyBool

typeOf (BinOp op e1 e2) = do
       ty1 <- typeOf e1 
       ty2 <- typeOf e2
       primTypeOf op ty1 ty2

typeOf (Var n) = do
       env <- get
       case lookup n env of
         Nothing -> throwTE $ "undefined variable " ++ n
         Just v -> return v

typeOf f@(FunCall n args) = do
-- FIXME
--  env <- get
-- 1. The variable n has to be defined 

-- 2. n has to be a function
-- 3. Each element of args has to be well typed
-- 4. The type of each argument in arg must be the same as the corresponding type
--    of the parameter in the functions parameter list
--  return TyInt -- FIXME (this stub assumes all funcs 
               --        return int, no checking done)  

  env <- get       
  tyn <- typeOf (Var n)       
  when (not(isVarDefined n env)) $ throwTE $ "function " ++ n ++ " is undefined"       
  case lookup n env of         
	Just (TyInt) -> throwTE $ n ++ " is not a function, yarrrr"         
	Just (TyBool) -> throwTE $ n ++ " is not a function, scurvy!"         
	Just (TyFun rt ty) -> do            
							argTypeList <- mapM typeOf args           
							when (argTypeList /= ty)          
								(throwTE $ "argument types for " ++ n ++ " aint right")           	
  
							return rt


typeOf _ = error "ICE: Unrecognized expression in typeOf"

-----------------------------
-- Type check a statement  --
-----------------------------

-- This wrapper function will call typeOK', catch any type errors, 
-- and write them to the error log. Hence, if you wish to continue
-- type checking even in case of errors, use typeOK. If you wish
-- to give up for the current statement, use typeOK'.
typeOK :: Stmt -> TypingM ()
typeOK s = catchError (typeOK' s) tell

-- This function may throw a type error
typeOK' :: Stmt -> TypingM ()

typeOK' Skip = return ()

typeOK' (If e s1 s2) = do
  tye <- typeOf e
  when (tye /= TyBool) $ tellTE "condition of if should be bool"
  typeOK s1
  typeOK s2

typeOK' (Assignment s e) = do
-- The variable s has to be defined
-- The type of the expression e has to be the same as the declared type of s
  tyv <- typeOf (Var s)
  tye <- typeOf e
  when (tye /= tyv) $ 
       throwTE $ "mutiny! assignment expecting type " ++ 
               show tyv ++ " got type " ++ show tye

typeOK' (While e b) = do
-- FIXME Should be clear how While is type checked
  tye <- typeOf e
  when (tye /= TyBool) $ tellTE "parlay! condition of when should be bool"
  typeOK b
--  return () -- while loops are not checked at all

typeOK' (VarDecl ty v e) = do
  env <- get
  when (isVarDefinedInInnermostScope v env) 
           (throwTE $ "variable already declared " ++ v)
  tye <- typeOf e
-- FIXME make sure that the declared type and the initializer type
-- agree
  when (ty /= tye) $ throwTE "type of variable is not the same as the type of its initializer expression"
  modify (newVar v tye)

typeOK' (Block ss) = do
-- Every statement in ss should be well typed
-- Typing environment should be restored to its original 
-- state after ss have been type checked
  enterBlock
  mapM_ typeOK ss 
  exitBlock
  
  
  -- it's checking for the return before it gets int main(), so there's a type error as it
  -- can't find a corresponding type for any return statement in the environment
  
  
typeOK' (FunDecl ty n pars (Block ss)) = do
-- FIXME
  env <- get
  modify (newVar "$ret" ty)
-- When type checking ss, the parameter name-->paramter type bindings should
--   be in the environment
  mapM_ (\(a,b) -> modify (newVar a b)) pars
-- Note that type checking a return statement in ss will require some
--   way of knowing what the return type "ty" is. One way to deal with this
--   is to add a special binding like ("$ret", ty) into the typing environment
  modify (newVar n (TyFun ty (map snd pars)))
-- n should not yet be defined in the current scope
  when (isVarDefinedInInnermostScope n env) 
            (throwTE $ "fuction already declared " ++ n ++ " or existing variable name")
-- There should be no duplicate parameter names in pars
  when (nub pars /= pars)
			(throwTE $ "duplicate parameters in function" ++ n)
-- When type checking ss, a binding for n should be in the environment
--   to allow recursive calls.
  mapM_ typeOK ss
  
  
--  return () -- function declarations are not checked at all

typeOK' (Return expr) = do
-- FIXME:
-- Look for the special $ret variable in the environment. 
-- Let its type be 'tyret'.
  env <- get
  tyret <- typeOf expr
  case lookup "$ret" env of
    Just v -> do
                when (v /= tyret) 
                        (throwTE $ "type of return does not match env")
    Nothing -> throwTE $ "undefined return argh"
 
-- Make sure that expr has type 'tyret'.
--  return () -- FIXME: currently no checking done


enterBlock :: TypingM ()
enterBlock = modify addMarker 

exitBlock :: TypingM ()
exitBlock = modify removeMarker


isArithmeticOp OpPlus = True
isArithmeticOp OpMinus = True
isArithmeticOp OpMultiplies = True
isArithmeticOp OpDivides = True
isArithmeticOp _ = False

isEqOp OpEqual = True
isEqOp OpNotEqual = True
isEqOp _ = False

isOrdOp OpLess = True
isOrdOp OpLessE = True
isOrdOp OpGreater = True
isOrdOp OpGreaterE = True
isOrdOp _ = False

-- The primitive functions of our language
primTypeOf OpPlus TyInt TyInt = return TyInt
primTypeOf OpMinus TyInt TyInt = return TyInt
primTypeOf OpMultiplies TyInt TyInt = return TyInt
primTypeOf OpDivides TyInt TyInt = return TyInt
primTypeOf op _ _ | isArithmeticOp op = throwTE $ show op ++ " requires int parameters."
primTypeOf OpEqual TyInt TyInt = return TyBool
primTypeOf OpEqual TyBool TyBool = return TyBool
primTypeOf OpNotEqual TyInt TyInt = return TyBool
primTypeOf OpNotEqual TyBool TyBool = return TyBool
primTypeOf op _ _ | isEqOp op = throwTE $ "equality operator requires int parameters."
primTypeOf OpLess TyInt TyInt = return TyBool
primTypeOf OpLessE TyInt TyInt = return TyBool
primTypeOf OpGreater TyInt TyInt = return TyBool
primTypeOf OpGreaterE TyInt TyInt = return TyBool
primTypeOf op _ _ | isOrdOp op = throwTE $ "comparison operator requires int parameters."
-- FIXME 
-- Equality/inequality/comparison operators are not checked properly
primTypeOf x l r = error $ 
                 "ICE: type error in operation: " ++ show x ++ " " ++ show l ++ " " ++ show r
