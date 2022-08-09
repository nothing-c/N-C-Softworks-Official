-- unifc: The Unified Compiler
import System.Environment
import System.Process
import GHC.Conc

-- In compilerFile: use the format
-- .[file extenstion] [compiler and options]

main :: IO ()
main = do
    args <- getArgs
    if (length args == 0) 
        then do 
            putStrLn "Usage: unifc file file file..."
            putStrLn "You can use shell quoting to pass further options"
            putStrLn "I.e, unifc 'ex.c -o ex'"
        else do
            compilerFileCont <- readFile compilerFile
            sequence $ map (\x -> (putStrLn $ "Compiling " ++ (last $ words x)) >> (forkIO (callCommand x))) (map (\x -> getCompiler (lines compilerFileCont) x) args)
            -- This is to keep the compiler from throwing a fit over IO () vs IO ThreadId
            putStrLn ""
    where
        -- For Windows:
        -- compilerFile = "c:\\Users\\YOUR USER PROFILE HERE\\unifc"
        -- For *NIX:
        -- compilerFile = "~/.unifc"

getCompiler :: [String] -> String -> String
getCompiler fileCont sourceFile 
    | (findExt sourceFile (head fileCont)) = (unwords . tail $ words (head fileCont)) ++ " " ++ sourceFile
    | otherwise = getCompiler (tail fileCont) sourceFile
    where
    findExt sourceFileName line
        | line !! 0 /= '.' = False
        | ((split '.' sourceFileName) !! 1) == (tail . head $ words line) = True
        | otherwise = False

split :: Char -> String -> [String]
split delim str = words [if c == delim then ' ' else c | c <- str]
