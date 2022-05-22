--speedy haskell interpretation of gnu yes
import System.Environment
import Control.Concurrent

main :: IO ()
main = do
	arg <- getArgs
	if length arg > 0 then loop (head arg) else loop "y"

loop :: String -> IO ()
loop x = putStrLn "y" >> loop x

