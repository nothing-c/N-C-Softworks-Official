/*
     ###         ###       #########  ###########     ##########   #########  #############
    ######      ###       ###        ###             ###    ###   ###             ###
   ###  ###    ###       ###          ##########    ###    ###   ########        ###
  ###    ###  ###  ###  ###                   ###  ###    ###   ###             ###
 ###      ######       ###                   ###  ###    ###   ###             ###
###        ###        ###########  ###########   ##########   ###             ###

*/


/*
N-C SOFTWORKS NC-GET v1.2
Lightweight version of wget/curl
Usage: nc-get [url]
*/
package main;

import(
	"net/http"
	"io/ioutil"
	"strings"
	"fmt"
	"os"
	"time"
)

func main(){
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
			tmp := strings.Split(os.Args[1], "/")
			realname = tmp[(len(tmp) - 1)]
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

