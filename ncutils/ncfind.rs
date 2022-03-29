/*
     ###         ###       #########  ###########     ##########   #########  #############
    ######      ###       ###        ###             ###    ###   ###             ###
   ###  ###    ###       ###          ##########    ###    ###   ########        ###
  ###    ###  ###  ###  ###                   ###  ###    ###   ###             ###
 ###      ######       ###                   ###  ###    ###   ###             ###
###        ###        ###########  ###########   ##########   ###             ###

*/

/*
N-C Find
Match string in a file, and output to stdout
Usage: ncfind [desired string] [file]
*/

use std::env;
use std::fs::File;
use std::io::{self, BufReader};
use std::io::BufRead;
use std::process;

fn main() -> io::Result<()> {
	/* Nab args */
	let args: Vec<String> = env::args().collect();
	if args.len() < 2 {
		println!("Too few args!");
		process::exit(0x0100);
	} else if args.len() < 3 {
		/* Search stdin */
		let findstr = &args[1][..];
		/* Lock stdin to iterate over lines */
		for line in io::stdin().lock().lines() {
			if let Ok(str) = line {
				if str.contains(&findstr) {
					println!("{}", str);
				}
			}
		}
	} else {
		/* Find in file */
		let file = File::open(&args[2])?;
		/* This is dumb, but it's the only way I can use contains() */
		let findstr = &args[1][..];
		let reader = BufReader::new(file);
		/* Why did they have to make Result its own type instead of a string? */
		for line in reader.lines() {
			/* Match the substring */
			if let Ok(str) = line {
				if str.contains(&findstr) {
					println!("{}", str);
				}
			}
		}
	}

	Ok(())
}


