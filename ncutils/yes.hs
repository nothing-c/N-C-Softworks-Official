import System.Environment

-- This reinforces my belief that Haskell is one of the most stupid
-- programming languages in the world

main :: IO ()
main = do 
	arg <- getArgs
	test arg

test arg
	| arg == [] = loop "y"
	| otherwise = loop $ head arg

loop x = putStrLn x >> loop x
