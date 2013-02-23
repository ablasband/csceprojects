

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
--  nSnd <- case lookup n env of
--         Nothing -> throwTE $ "scurvy! undefined function " ++ n
--		 Just v -> return v
-- 2. n has to be a function
--  when not (nSnd == TyInt || nSnd == TyBool)
-- or is it tyf /= TyFun
--		 throwTE $ "shiver me timbers! not a function"
-- 3. Each element of args has to be well typed
--  mapM typeOK args
-- 4. The type of each argument in arg must be the same as the corresponding type
--    of the parameter in the functions parameter list
--  if (mapM (\(_,b) \v -> (b /= v) args (lookup n env)) then $ tellTE "args do not match whats in the env yarr"
  return TyInt -- FIXME (this stub assumes all funcs 
               --        return int, no checking done)
			   
--  return nSnd

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
  
typeOK' (FunDecl ty n pars (Block ss)) = do
-- FIXME
  env <- get
-- n should not yet be defined in the current scope
  when (isVarDefinedInInnermostScope n env) 
            (throwTE $ "fuction already declared " ++ n ++ " or existing variable name")
-- There should be no duplicate parameter names in pars
  when (length (removeDuplicates pars) /= length pars)
			(throwTE $ "duplicate parameters in function" ++ n)
-- When type checking ss, a binding for n should be in the environment
--   to allow recursive calls.
  mapM typeOK ss
  modify (newVar n ty)
-- When type checking ss, the parameter name-->paramter type bindings should
--   be in the environment
  mapM (\(a,b) -> modify (newVar a b)) pars
-- Note that type checking a return statement in ss will require some
--   way of knowing what the return type "ty" is. One way to deal with this
--   is to add a special binding like ("$ret", ty) into the typing environment
  modify (newVar "$ret" ty)
--  return () -- function declarations are not checked at all

typeOK' (Return expr) = do
-- FIXME:
-- Look for the special $ret variable in the environment. 
-- Let its type be 'tyret'.
  env <- get

  tyret <- case lookup "$ret" env of
         Nothing -> throwTE $ "undefined return "
         Just v -> return v
  
-- Make sure that expr has type 'tyret'.
  when (typeOf expr /= tyret)
			(throwTE $ "type of return does not match env")
--  return () -- FIXME: currently no checking done
  
-- Remove duplicate values from a params list
removeDuplicates :: Eq a => [a] -> [a]
removeDuplicates [] = []
removeDuplicates (x:xs) = x : removeDuplicates (filter (\y -> not (x == y)) xs)

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
-- FIXME 
-- Equality/inequality/comparison operators are not checked properly
primTypeOf x l r = error $ 
                 "ICE: type error in operation: " ++ show x ++ " " ++ show l ++ " " ++ show r
