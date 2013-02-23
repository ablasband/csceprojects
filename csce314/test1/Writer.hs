{-# OPTIONS_GHC -fglasgow-exts #-}
import Char

newtype Writer w a = Writer (a, w)

runWriter (Writer (a, w)) = (a, w)

instance Monad (Writer [ls]) where
    return a = Writer (a, [])
    (Writer (a, w)) >>= f =
        let Writer (a', w') = f a 
        in 
         Writer (a', w ++ w')


tell :: w -> Writer w ()
tell s = Writer ((), s)

listen :: Writer w a -> Writer w (a, w)
listen (Writer (a, w)) = Writer ((a, w), w)

pass :: Writer w (a, w -> w) -> Writer w a
pass (Writer ((a, f), w)) = Writer (a, f w)

listens :: Monad (Writer w) => (w -> b) -> Writer w a -> Writer w (a, b)
listens f m = do (a, w) <- listen m
                 return (a, f w)

censor :: Monad (Writer w) => (w -> w) -> Writer w a -> Writer w a
censor f m = pass $ do a <- m
                       return (a, f)
          

detect s = do
    let ws = words s
    mapM_ examineWord ws

examineWord w = do
  if (isUpper (head w)) 
     then 
         tell (w++" ")         
--         censor (map Char.toUpper) $ tell (w++" ")         
     else  
         return ()
  

story2 = "Donald Duck is an American cartoon character from The Walt Disney Company. Donald is a white anthropomorphic duck with a yellow-orange bill, legs, and feet. He usually wears a sailor shirt, cap, and a red or black bow tie, but no trousers (except when he goes swimming). Donald's most famous personality trait is his easily provoked and explosive temper."

test2 = let (a, w) = runWriter (detect story2) in
        w
