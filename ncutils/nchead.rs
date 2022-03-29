/*
N-C Head
Print first x lines of a file
Usage: nchead [# of lines] file
*/

use std::env;
use std::fs::File;
use std::io::{self, BufReader};
use std::io::BufRead;

fn main() -> io::Result<()> {
	/* Nab args */
	let args: Vec<String> = env::args().collect();\
	/* Convert string to int (this looks ridiculous */
	let numstr = args[1].parse::<i32>().unwrap();
	let mut count = 0;
	/* Open file */
	let file = File::open(&args[2])?;
	let reader = BufReader::new(file);

	for line in reader.lines() {
		if count < numstr {			
			println!("{}", line?);
			count += 1;
		} else {
			break;
		}
	}

	Ok(())
}
