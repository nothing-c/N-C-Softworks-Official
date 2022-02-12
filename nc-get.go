/*
     ###         ###       #########  ###########     ##########   #########  #############
    ######      ###       ###        ###             ###    ###   ###             ###
   ###  ###    ###       ###          ##########    ###    ###   ########        ###
  ###    ###  ###  ###  ###                   ###  ###    ###   ###             ###
 ###      ######       ###                   ###  ###    ###   ###             ###
###        ###        ###########  ###########   ##########   ###             ###

*/


/*
N-C SOFTWORKS NC-GET v1.1
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
	"time"
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
	regex, _ := regexp.Compile("[A-Za-z0-9]*.[A-Za-z]+");
	client := &http.Client {
		Timeout: time.Second * 60,
	}
	realname := ""
	if len(os.Args) < 2 {
		fmt.Println("Error: no URL provided")
		os.Exit(1)
	} else {
		req, _ := http.NewRequest("GET", os.Args[1], nil)
		req.Header.Set("User-Agent", "Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/97.0.4692.99 Safari/537.36")
		fmt.Println("Sending request")
		resp, err := client.Do(req)
		if err != nil {
			panic("Request blocked, or you don't have internet")
		}
		if len(os.Args) < 3 {
			possible := regex.FindAllStringSubmatch(os.Args[1],-1);
			filename := possible[len(possible) - 1];
			realname = checker(filename[0]);
		} else if len(os.Args) < 4 {
			realname = os.Args[2]
		} else {
			fmt.Println("Too many arguments")
			os.Exit(1)
		}
		defer resp.Body.Close()
		pulled, _ := ioutil.ReadAll(resp.Body);
		ioutil.WriteFile(realname, []byte(pulled), 0666);
		fmt.Println("Done");
	}
}

