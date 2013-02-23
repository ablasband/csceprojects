
module Main where

import Test.HUnit
import System.Exit

-- Compute the nth Fibonacci number
fibonacci :: Int -> Int

-- Take the first N elements of a list
firstN :: Int -> [a] -> [a]

-- Flatten a list of lists to a single list formed by concatenation
flatten :: [[a]] -> [a]
 
-- Is a value an element of a list?
isElement :: Eq a => a -> [a] -> Bool

-- Remove duplicate values from a list
removeDuplicates :: Eq a => [a] -> [a]

fibonacci = undefined
firstN = undefined
flatten = undefined
isElement = undefined
removeDuplicates = undefined

union :: Eq a => [a] -> [a] -> [a]

intersection :: Eq a => [a] -> [a] -> [a]

subset :: Eq a => [a] -> [a] -> Bool 
-- subset a b is True if a is a subset of b

setEqual :: Eq a => [a] -> [a] -> Bool

powerSet :: [a] -> [[a]]

union = undefined
intersection = undefined
subset = undefined
setEqual = undefined
powerSet = undefined

myTestList = 
    TestList [
               "fibonacci" ~: fibonacci 4 ~=? 3

             , "take" ~: (firstN 3 "abcdef") ~=? "abc"
                     
             , "isElement 1" ~: (isElement 'c' "abcd") ~=? True
             , "isElement 2" ~: (isElement 'e' "abcd") ~=? False

             , "removeDuplicates 1" ~: 'a' `elem` (removeDuplicates "abcdaab") ~=? True             
             , "removeDuplicates 2" ~: 'b' `elem` (removeDuplicates "abcdaab") ~=? True             
             , "removeDuplicates 3" ~: 'c' `elem` (removeDuplicates "abcdaab") ~=? True             
             , "removeDuplicates 4" ~: 'd' `elem` (removeDuplicates "abcdaab") ~=? True             
             , "removeDuplicates 5" ~: length (removeDuplicates "abcdaab") ~=? 4
             , "removeDuplicates 6" ~: length (removeDuplicates "abc") ~=? 3

             , "flatten 1" ~: flatten [[]::[Int]] ~=? []
             , "flatten 2" ~: flatten [[]::[Int], [], []] ~=? []
             , "flatten 3" ~: flatten [[1], [2, 3, 4], [], [5, 6]] ~=? [1, 2, 3, 4, 5, 6]

             , "union 1" ~: setEqual (union "abc" "baf") "abcf" ~=? True
             , "union 2" ~: setEqual (union "abc" "defg") "abcdefg" ~=? True

             , "intersection 1" ~: setEqual (intersection "abc" "baf") "ab" ~=? True
             , "intersection 2" ~: setEqual (intersection "abc" "defg") "" ~=? True

             , "powerSet 1" ~: setEqual (powerSet ([]::[Int])) [[]] ~=? True
             , "powerSet 2" ~: setEqual (powerSet [1]) [[], [1]] ~=? True
             , "powerSet 3" ~: setEqual (powerSet [1, 2]) [[], [1], [2], [1, 2]] ~=? True

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
