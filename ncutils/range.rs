/*
     ###         ###       #########  ###########     ##########   #########  #############
    ######      ###       ###        ###             ###    ###   ###             ###
   ###  ###    ###       ###          ##########    ###    ###   ########        ###
  ###    ###  ###  ###  ###                   ###  ###    ###   ###             ###
 ###      ######       ###                   ###  ###    ###   ###             ###
###        ###        ###########  ###########   ##########   ###             ###
*/


/*
N-C Number Range Generator (inclusive)
Usage: range [base] [end]
Why: for shellscripts that don't use BASH's incrementing for loops
*/

use std::env;

fn main() {
	/* Args */
	let args: Vec<String> = env::args().collect();
	let mut base = args[1].parse::<i64>().unwrap();
	let top = args[2].parse::<i64>().unwrap();
	/* Since it's inclusive, we use <= */
	while base <= top {
		/* No println! because we're generating a range for sh */
		print!("{} ", base);
		base += 1;
	}
}