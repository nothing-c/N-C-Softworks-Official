/*
     ###         ###       #########  ###########     ##########   #########  #############
    ######      ###       ###        ###             ###    ###   ###             ###
   ###  ###    ###       ###          ##########    ###    ###   ########        ###
  ###    ###  ###  ###  ###                   ###  ###    ###   ###             ###
 ###      ######       ###                   ###  ###    ###   ###             ###
###        ###        ###########  ###########   ##########   ###             ###

*/


/*
N-C SOFTWORKS NC-GET v1.0
Lightweight version of wget/curl
Usage: nc-get [url]
*/
package main;

import(
	"net/http"
	"io/ioutil"
	"regexp"
	"fmt"
	"os"
)

func checker(name string)(filename string){
	i := 0;
	filename = name;
	for {
		_, err := ioutil.ReadFile(string(filename));
		if err != nil{
			return filename;
		} else {
			//concat string and int
			filename = fmt.Sprint(filename, i);
		}
		i++;
	}
}

func main(){
	pull, err := http.Get(os.Args[1]);
	if err != nil {
		fmt.Println(err);
	} else {
		//grab only extension
		regex, _ := regexp.Compile("[A-Za-z0-9]*.[A-Za-z]+");
		//to get the name of the file
		possible := regex.FindAllStringSubmatch(os.Args[1],-1);
		filename := possible[len(possible) - 1];
		realname := checker(filename[0]);
		pulled, _ := ioutil.ReadAll(pull.Body);
		ioutil.WriteFile(realname, []byte(pulled), 0666);
		fmt.Println("done");
	}
}
