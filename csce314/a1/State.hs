newtype State s a = State (s -> (a, s))  

runState (State f) s = f s
 
instance Monad (State s) where 
    return a        = State $ \s -> (a, s)
    (State f) >>= g = State $ \s -> let (v, s') = f s 
                                    in runState (g v) s' 

get :: State s s
get = State $ \s -> (s, s)

put :: s -> State s ()
put s = State $ \_ -> ((), s)

modify :: (s -> s) -> State s ()
modify f = do
    s <- get
    put (f s)



data Tree = Leaf Int | Branch2 Tree Tree | Branch3 Tree Tree Tree 
     deriving Show

oddLeafs :: Tree -> State Int ()
oddLeafs (Branch2 l r) = do
  oddLeafs l
  oddLeafs r
oddLeafs (Branch3 l m r) = do
  oddLeafs l
  oddLeafs m
  oddLeafs r

oddLeafs (Leaf i) = do
  s <- get 
  if (odd i) then put (s+1) else return ()

  
tree = Branch3 
       (Branch2 (Leaf 7) (Leaf 3)) 
       (Leaf 1) 
       (Leaf 8)
  
  
test = runState (oddLeafs tree) 0

