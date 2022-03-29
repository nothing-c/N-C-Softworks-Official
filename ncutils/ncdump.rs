/*
N-C Dumper
Outputs file contents to stdout
Usage: ncdump file1 file2 file3
*/

use std::env;
use std::fs::File;
use std::io::{self, BufReader};
use std::io::BufRead;

fn main() -> io::Result<()> {
	/* Nab args */
	let args: Vec<String> = env::args().collect();
	let mut count = 0;
	/* There are no C-style for loops ): */
	for arg in args {
		if count == 0 {
			/* Skip program name */
			count += 1;
			continue;
		} else {
			/* It took me way too long to get this working */
			let file = File::open(&arg)?;
			/* Why can't I just read chars? This isn't Java */
			let reader = BufReader::new(file);
			for line in reader.lines() {
				println!("{}", line?);
			}
		}
	}
	Ok(())
}









