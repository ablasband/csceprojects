import Prelude hiding (Either(..))

data Either a b = Left a | Right b
type Error b = Either String b

instance Monad (Either a) where
    return = Right
    x >>= f = case x of 
                Left l -> Left l
                Right r -> f r

throwError :: String -> Error b
throwError = Left

catchError :: Error a -> (String -> Error a) -> Error a
catchError (Left e) handler = handler e
catchError x _ = x

runError (Right x) = x

story1 = "Only short words here"
story2 = "Donald Duck is an American cartoon character from The Walt Disney Company. Donald is a white anthropomorphic duck with a yellow-orange bill, legs, and feet. He usually wears a sailor shirt, cap, and a red or black bow tie, but no trousers (except when he goes swimming). Donald's most famous personality trait is his easily provoked and explosive temper."
story3 = "Some words are suspi_cious, eh?"

process :: String -> Error String
process story = 
    let ws = words story in
      do
      { mapM_ check1 ws
      ; mapM_ check2 ws
      ; return "OK" 
      } 
        `catchError` (\e -> return $ "Error occurred: " ++ e)



check1 :: String -> Error ()
check1 w = if length w < 13 then return ()
           else throwError $ w ++ " was too long"

check2 :: String -> Error ()
check2 w = if not ('_' `elem` w) then return ()
           else throwError $ w ++ " contains an illegal character"

test1 = runError (process story1)
test2 = runError (process story2)
test3 = runError (process story3)