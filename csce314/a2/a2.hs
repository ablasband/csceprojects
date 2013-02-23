-- Graham Leslie
-- CSCE 314
-- Assignment 2

module Main where

import Data.Char -- for toUpper
import Test.HUnit
import System.Exit

-- EX 1 --

-- generate all triad such that x^2 + y^2 = z^2 where x,y,z < n
triads :: Int -> [(Int, Int, Int)]
triads 0 = []
triads n = [(x,y,z) | x<-[1..n], y<-[1..n], z<-[1..n], x^2 + y^2 == z^2]

-- generate a list of factors for n, cut off the tail for use with perfect
factor :: Int -> [Int]
factor 0 = []
factor n = [x | x<-[1..n], mod n x == 0, not (x == n)]

-- generate an infinite list of perfect numbers
perfect :: [Int]
perfect = [x | x<-[1..], sum (factor x) == x]

-- EX 2 --

-- merge merges two sorted lists
merge :: Ord a => [a] -> [a] -> [a]
merge [] [] = []
merge xs [] = xs
merge [] ys = ys
merge (x:xs) (y:ys) = if x <= y
	then x : merge xs (y:ys)
	else y : merge (x:xs) ys
	
-- mergeP is a parameterized merge
mergeP :: Ord a => (a -> a -> Bool) -> [a] -> [a] -> [a]
mergeP pred [] [] = []
mergeP pred xs [] = xs
mergeP pred [] ys = ys
mergeP pred (x:xs) (y:ys) = 
	case pred x y of
	True -> x : mergeP pred xs (y:ys)
	False -> y : mergeP pred (x:xs) ys
	
-- mergesorts a list
mergeSort :: Ord a => [a] -> [a]
mergeSort [] = []
mergeSort [x] = [x]
mergeSort xs
    = merge (mergeSort a) (mergeSort b)
    where
    (a, b) = splitAt (length xs `div` 2) xs
    
-- mergesorts using a parameter p
mergeSortP :: Ord a => (a -> a -> Bool) -> [a] -> [a]
mergeSortP pred [] = []
mergeSortP pred [x] = [x]
mergeSortP pred xs
    = mergeP pred (mergeSortP pred a) (mergeSortP pred b)
    where
    (a, b) = splitAt (length xs `div` 2) xs
    
-- EX 3 --

-- multiply multiplies all elements of a list
multiply :: [Int] -> Int
multiply [] = 1
multiply xs = foldl (*) 1 xs

-- concatenate concatenates a list of strings into one string
concatenate :: [String] -> String
concatenate [] = ""
concatenate xs = foldl (++) ""  xs 

-- fcn name is too long, keep ones whose length is odd, uppercase and concat em
concatenateAndUpcaseOddLengthStrings :: [String] -> String
concatenateAndUpcaseOddLengthStrings [] = ""
concatenateAndUpcaseOddLengthStrings xs = map toUpper (concat ([y | y<-xs, odd (length y)]))

-- insert helper function for insertionSort
insert :: Ord a => a -> [a] -> [a]
insert x [] = [x]
insert x (y:ys) =
	case x <= y of
	True -> (x:y:ys)
	False -> y:(insert x ys)

-- insertionSort implements insertion sort on a list
insertionSort :: Ord a => [a] -> [a]
insertionSort [] = []
insertionSort [x] = [x]
insertionSort (x:xs) = insert x (insertionSort xs)

-- finds the maximum element in a list
maxElementOfAList :: Ord a => [a] -> a
maxElementOfAList xs = foldr1 max xs

-- keepInBetween keeps the stuff between the provided interval
keepInBetween :: Int -> Int -> [Int] -> [Int]
keepInBetween a b [] = []
keepInBetween a b xs = [y | y<-xs, y >= a, y < b]

-- EX 4 --

-- tree datatype
data Tree a b = Branch b (Tree a b) (Tree a b) 
		| Leaf a

-- make a way to show a leaf or a tree
instance (Show a, Show b) => Show (Tree a b) where
	show (Leaf a) = "leaf: " ++ (show a)
	show (Branch b l r) = "branch: " ++ (show b) ++ "{" ++ (show l) ++ "," ++ (show r) ++ "}"

-- traversals
preorder :: (a -> c) -> (b -> c) -> Tree a b -> [c]
preorder mapA mapB (Leaf n) = [x] where
			x = mapA n
preorder mapA mapB (Branch b l r) = [x] ++ y ++ z where
			x = mapB b
			y = preorder mapA mapB l
			z = preorder mapA mapB r
			
inorder :: (a -> c) -> (b -> c) -> Tree a b -> [c]
inorder mapA mapB (Leaf n) = [x] where
			x = mapA n
inorder mapA mapB (Branch b l r) = x ++ [y] ++ z where
			x = inorder mapA mapB l
			y = mapB b
			z = inorder mapA mapB r
			
postorder :: (a -> c) -> (b -> c) -> Tree a b -> [c]
postorder mapA mapB (Leaf n) = [x] where
			x = mapA n
postorder mapA mapB (Branch b l r) = x ++ y ++ [z] where
			x = postorder mapA mapB l
			y = postorder mapA mapB r
			z = mapB b

-- EX 5 --
-- requires 1. str literals, 2. concat of strings, 3. comparison of strings for eq
-- and therefore booleans

data S = LitString String
	| LitBool Bool
	| Concat S S
	| Equals S S

toStr :: Bool -> String
toStr b
	| b == True = "True"
	| otherwise = "False"

eval :: S -> S
eval (LitString a) = LitString a
eval (Concat (LitString a) (LitString b)) = LitString $ a ++ b
eval (Concat (LitBool a) (LitBool b)) = LitString $ (toStr a) ++ (toStr b)
eval (Equals (LitString a) (LitString b)) = LitString $ toStr(a == b)
eval (Equals (LitBool a) (LitBool b)) = LitString $ toStr $ (toStr a) == (toStr b)

instance Show S where
	show (LitString s) = show s
	show (LitBool b) = show b
	show (Concat a b) = show a ++ " " ++ show b
	show (Equals a b) = show a ++ " == " ++ show b

myTestList = 
    TestList [
               "triads" ~: (triads 5) ~=? [(3,4,5),(4,3,5)]

             , "factor" ~: (factor 10) ~=? [1,2,5]
             
             , "perfect" ~: (take 3 perfect) ~=? [6,28,496]
             
             , "mergeSort" ~: (mergeSort [3,2,1,0]) ~=? [0,1,2,3]
             
             , "mergeSortP" ~: (mergeSortP (>=) [0,1,2,3]) ~=? [3,2,1,0]
             
             , "multiply" ~: (multiply [1,2,3,4]) ~=? 24
             
             , "concatenate" ~: (concatenate ["hello","string"]) ~=? "hellostring"
             
             , "concatenateAndUpcaseOddLengthStrings" ~: (concatenateAndUpcaseOddLengthStrings ["odd","even","odd"]) ~=? "ODDODD"
             
             , "insertionSort" ~: (insertionSort [3,2,1,0]) ~=? [0,1,2,3]
             
             , "maxElementOfAList" ~: (maxElementOfAList [0,1,2,3,4,5,-1]) ~=? 5
             
             , "keepInBetween" ~: (keepInBetween 1 3 [0,1,2,3,4]) ~=? [1,2]
            
             ]
 
main = do c <- runTestTT myTestList          
          putStrLn $ show c
          let errs = errors c
              fails = failures c
          exitWith (codeGet errs fails)
          
          
codeGet errs fails
 | fails > 0       = ExitFailure 2
 | errs > 0        = ExitFailure 1
 | otherwise       = ExitSuccess
