/*
     ###         ###       #########  ###########     ##########   #########  #############
    ######      ###       ###        ###             ###    ###   ###             ###
   ###  ###    ###       ###          ##########    ###    ###   ########        ###
  ###    ###  ###  ###  ###                   ###  ###    ###   ###             ###
 ###      ######       ###                   ###  ###    ###   ###             ###
###        ###        ###########  ###########   ##########   ###             ###
*/

/*
  N-C Softworks Putc v1.0
  Usage: putc [decimal number]
*/

#include <stdio.h>
#include <stdlib.h>

int main (int argc, char * argv[]) {
  int print;
  if (argc < 2) {
    puts("Error: no char number provided");
    puts("Usage: putc [decimal number]");
    return 1;
  }
  print = atoi(argv[1]);
  putchar(print);
  return 0;
}
