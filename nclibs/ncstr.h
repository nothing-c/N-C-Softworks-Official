/*
     ###         ###       #########  ###########     ##########   #########  #############
    ######      ###       ###        ###             ###    ###   ###             ###
   ###  ###    ###       ###          ##########    ###    ###   ########        ###
  ###    ###  ###  ###  ###                   ###  ###    ###   ###             ###
 ###      ######       ###                   ###  ###    ###   ###             ###
###        ###        ###########  ###########   ##########   ###             ###

*/

/*
  N-C Softworks C Safe String Library
  Contents: ncgets(), ncugets()
*/

#include <stdlib.h>

/* Default buffer size (changeable) */
#define BUF 80

/* 
   Read a limited number of characters into a buffer from STDIN
   Return a pointer to that array (will need to be freed)
   Will not overrun, and will simply chop off the rest of
   the inserted characters
   Commented lines are optionally changeable
*/
char * ncgets(int bufsize) {
  char c;
  char *buf = malloc(bufsize);
  char *ret = buf;
  int i = 0;
  //while ((c = getchar()) != EOF) {
  while ((c = getchar()) != '\n') {
    /* As long as we're not approaching the end, keep going */
    if (i < bufsize - 1) {
      i++;
      *buf++ = c;
    } else {
      /* Terminate */
      *buf++ = '\0';
      /* Safe, will auto-return if it runs out of space */
      return ret;
    }
  }
  *buf++ = '\0';
  return ret;
}

/*
  "Unlimited gets()", read an unlimited number of characters 
  into a buffer from STDIN
  Return a pointer to that array (will need to be freed)
  Commented line policy is the same as above
*/
char * ncugets() {
  int bufsize = BUF;
  char *buf = malloc(BUF);
  char *ret = buf;
  char c;
  int i = 0;
  //while ((c = getchar()) != EOF) {
  while ((c = getchar()) != '\n') {
    if (i < bufsize) {
      /* 
	 Note: this will waste space in memory if you have a string
	 one character longer than the buffer size
      */
      *(buf + i) = c;
      i++;
    } else {
      /* Add size to buffer */
      bufsize += 80;
      /* 
	 Reallocate space 
	 This just adds space, so you don't need strcpy 
      */
      buf = realloc(ret, bufsize);
      ret = buf;
    }
  }
  /* Terminate string */
  *(buf + i) = '\0';
  return ret;
}
