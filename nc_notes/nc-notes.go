/*
     ###         ###       #########  ###########     ##########   #########  #############
    ######      ###       ###        ###             ###    ###   ###             ###
   ###  ###    ###       ###          ##########    ###    ###   ########        ###
  ###    ###  ###  ###  ###                   ###  ###    ###   ###             ###
 ###      ######       ###                   ###  ###    ###   ###             ###
###        ###        ###########  ###########   ##########   ###             ###

*/

/*
N-C Notes v1.0
Usage: nc-notes [arg] [subject]
Notes: You're gonna need to set your own env vars to compile properly
*/

package main;

import (
       "os"
       "bufio"
       "strings"
       "fmt"
)

const (
      /* THIS NEEDS TO BE AN ABSOLUTE PATH */
      TAGFILE = "tags.txt"
)

func findtag(tag string)() {
     /* Working */
     tagfile,_ := os.Open(TAGFILE)
     reader := bufio.NewScanner(tagfile)
     for reader.Scan() {
     	 if strings.Contains(reader.Text(), tag) {
     	 	tmp := strings.Split(reader.Text(), ":")
		fmt.Println(tmp[0])
		 }
	}

}

func findfile(name string)() {
     /* Working */
     tagfile,_ := os.Open(TAGFILE)
     reader := bufio.NewScanner(tagfile)
     for reader.Scan() {
     	 if strings.Contains(reader.Text(), name) {
     	 	tmp := strings.Split(reader.Text(), ":")
		fmt.Println(tmp[1])
		 }
	}
}

func addtag(file string)() {
     /* Working */
     /* We fail silently, like REAL men! */
     dir, _ := os.Getwd()
     open,_ := os.Open(file)
     reader := bufio.NewReader(open)
     tags, _ := reader.ReadString('\n')
     list := strings.Split(tags, "#")
     fileout,_ := os.OpenFile(TAGFILE, os.O_APPEND|os.O_CREATE|os.O_WRONLY, 0644)
     fileout.WriteString(dir + "/" + file + ":" + list[1])
     fileout.Close()
}

func main() {
     if len(os.Args) < 3 {
     	panic("Not enough args!")
     }
     switch os.Args[1] {
     	    case "a":
	    	 addtag(os.Args[2])
	    case "f":
	    	 findfile(os.Args[2])
	    case "t":
	    	 findtag(os.Args[2])
	}
}