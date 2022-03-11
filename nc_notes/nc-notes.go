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
      TAGFILE = "~/tags.txt"
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
     /* Working, might wanna add a pwd for concrete path, but w/e */
     /* We fail silently, like REAL men! */
     open,_ := os.Open(file)
     reader := bufio.NewReader(open)
     tags, _ := reader.ReadString('\n')
     list := strings.Split(tags, "#")
     os.Open(TAGFILE)
     fileout,_ := os.Open(TAGFILE)
     write := bufio.NewWriter(fileout)
     fmt.Fprint(write, (file + ":" + list[1]))
     write.Flush()
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