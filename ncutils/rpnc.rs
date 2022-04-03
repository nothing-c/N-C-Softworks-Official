/*
     ###         ###       #########  ###########     ##########   #########  #############
    ######      ###       ###        ###             ###    ###   ###             ###
   ###  ###    ###       ###          ##########    ###    ###   ########        ###
  ###    ###  ###  ###  ###                   ###  ###    ###   ###             ###
 ###      ######       ###                   ###  ###    ###   ###             ###
###        ###        ###########  ###########   ##########   ###             ###
*/


/*
N-C Softworks RPN Calculator
RPN Calculator
Usage: rpnc (and then type) or | rpnc
	Ex: 1 3 + 3 + => 7
Notes: spaces aren't optional; use "l" for the last result of computation
*/

use std::io;
use std::io::BufRead;

/* We want all f64s (for precision, of course) */
fn eval(arr: Vec<&str>, last: f64) -> f64 {
	let mut stack: [f64; 10] = [0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0];
	let mut point = 0;
	for a in arr {
		/* Switch for math */
		let b = a.trim();
		match b {
			"+" => {
				point -= 2;
				stack[point] = stack[point] + stack[point + 1];
			}
			"-" => {
				point -= 2;
				stack[point] = stack[point] - stack[point + 1];
			}
			"/" => {
				point -= 2;
				stack[point] = stack[point] / stack[point + 1];
			}
			"*" => {
				point -= 2;
				stack[point] = stack[point] * stack[point + 1];
			}
			"%" => {
				point -= 2;
				stack[point] = stack[point] % stack[point + 1];
			}
			"l" => {
				stack[point] = last;
			}
			/* Exit */
			"quit" => {
				std::process::exit(0x0100);
			}
			"" => {
				/* Do nothing, we're just skipping here */
			}
			_ => {
				/* Convert to float and add to stack */
				stack[point] = a.trim().parse::<f64>().unwrap();
			}
			
		}
		point += 1;
	}
	return stack[0];
}

fn main() -> io::Result<()> {
	let mut lst: f64 = 0.0;
	/* Infinite */
	for buf in io::stdin().lock().lines() {
		/* This method chaining is ridiculous */
		let strvec: Vec<&str> = buf.as_ref().unwrap().split(' ').collect();
		lst = eval(strvec, lst);
		println!("{}", lst);
	}
	Ok(())
}