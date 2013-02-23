{-# OPTIONS_GHC -fglasgow-exts #-}
import Char

newtype Reader e a = Reader (e -> a)

runReader (Reader f) e = f e

instance Monad (Reader e) where 
    return a         = Reader $ \_ -> a 
    (Reader r) >>= f = Reader $ \e -> runReader (f (r e)) e 


ask = Reader (\e -> e)
local f c = Reader $ \e -> runReader c (f e)
 
asks sel = ask >>= return . sel

type WordMap = [(String, String)]


fillIn :: String -> Reader [(String, String)] String
fillIn s = do
  let ws = words s
  ws' <- mapM replace ws
  return $ unwords ws'

replace :: String -> Reader [(String, String)] String
replace s = do
  env <- ask 
  case lookup s env of
    Just w -> return w
    Nothing -> return s
--  asks $ maybe s id . lookup s

    
  
story = "It was a _1_ and _2_ night, and only _3_ where awake. " ++ 
        "I walked home _4_ and saw _5_ _6_\n"

wordList = "cold irrelevant zombies eerily collapsed bananas"
indices = "_1_ _2_ _3_ _4_ _5_ _6_"

newStory = let wmap = zip (words indices) (words wordList)
           in runReader (fillIn story) wmap


