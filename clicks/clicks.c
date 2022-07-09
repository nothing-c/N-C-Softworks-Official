/*
     ###         ###       #########  ###########     ##########   #########  #############
    ######      ###       ###        ###             ###    ###   ###             ###
   ###  ###    ###       ###          ##########    ###    ###   ########        ###
  ###    ###  ###  ###  ###                   ###  ###    ###   ###             ###
 ###      ######       ###                   ###  ###    ###   ###             ###
###        ###        ###########  ###########   ##########   ###             ###
*/

/*
  N-C Softworks AutoClicker v1.0
  Usage: clicks
         clicks [filename]
*/

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <windows.h>

#include "ncclicklib.h"

/* Maximum length of line */
#define MAXLINESIZE 24
/* Max number of chars in a number inputted */
#define MAXINTLENGTH 10

void readstr (FILE * handle);
void parse (char input[], int linenumber);
int parseint (char line[], int flag);
int leftright (char line[]);

int main (int argc, char * argv[]) {
  /* File to be opened */
  FILE * file;
  /* Error handling */
  errno = 0;
  if (argc > 1) {
    /* Open file, read-only */
    file = fopen(argv[1], "r");
    if (errno != 0) {
      perror("Error opening file");
      return 1;
    }
    readstr(file);
  } else {
    /* Read from stdin */
    readstr(stdin);
  }
  return 0;
}

/* Parse the file passed */
void readstr (FILE * handle) {
  int c;
  int counter = 0;
  int linenumber = 1;
  char line[MAXLINESIZE];
  while ((c = fgetc(handle)) != EOF) {
    if ((counter == MAXLINESIZE) || (c == '\n')) {
      parse(line, linenumber);
      counter = 0;
      linenumber++;
    } else {
      line[counter] = c;
      counter++;
    }
  }
  fputs("EOF", stdout);
}

void parse (char line[], int linenumber) {
  int xval;
  int yval;
  int secs;
  /* Flag for which mouse button to send to click, hold, raise */
  int buttonflag;
  /* Determine what we're working with */
  switch (line[0]) {
  case 'm':
    /* Move mouse */
    /* Convert ASCII to integer to plug into function */
    xval = parseint(line, 1);
    yval = parseint(line, 0);
    SetCursorPos(xval, yval);
    fprintf(stdout, "Cursor moved to %d,%d\n", xval, yval);
    break;
  case 'c':
    /* Click mouse */
    xval = parseint(line, 1);
    yval = parseint(line, 0);
    click(xval, yval, leftright(line));
    fprintf(stdout, "Clicked at %d,%d\n", xval, yval);
    break;
  case 'h':
    /* Hold mouse */
    xval = parseint(line, 1);
    yval = parseint(line, 0);
    hold(xval, yval, leftright(line));
    fprintf(stdout, "Button held at %d,%d\n", xval, yval);
    break;
  case 'r':
    /* Raise mouse */
    xval = parseint(line, 1);
    yval = parseint(line, 0);
    if (line[6] == 'r') {
      buttonflag = 1;
    } else {
      buttonflag = 0;
    }
    release(xval, yval, leftright(line));
    fprintf(stdout, "Button release at %d,%d\n", xval, yval);
    break;
  case 's':
    secs = parseint(line, 1);
    fprintf(stdout, "Sleeping for %d seconds\n", secs);
    sleep(secs);
    break;
  default:
    /* Print error message to stderr */
    fprintf(stderr, "Line %d ignored\n", linenumber);
    break;
  }
}

/*
  Function to parse the integers for movement
  flag is 1 for x, 0 for y
 */
int parseint (char line[], int flag) {
  /* Marker to start at */
  char offset1;
  /* Marker to stop at */
  char offset2;
  /* Location of offset1 */
  int start = 0;
  /* Location of offset2 */
  int end;
  /* String to hold the number */
  char * numstr = malloc(MAXINTLENGTH);
  /* Boundschecker */
  int bound = 0;
  /* Number to return */
  int ret = 0;
  /* Set the offsets */
  if (flag > 0) {
    offset1 = ' ';
    offset2 = ',';
  } else {
    offset1 = ',';
    offset2 = '\n';
  }
  /* Find the first offset */
  while (line[start] != offset1) {
    start++;
  }
  end = start;
  /* Find the second offset */
  while (line[end] != offset2) {
    end++;
  }
  for (int i = start + 1; i < end; i++) {
    /* Kill and return 0 if it goes over bounds */
    if (bound == MAXINTLENGTH) {
      fputs("Error parsing number: too large (numbers must be less that 10 chars long)\n", stderr);
      return 0;
    }
    /*
      Hack for getting the yval: if the char is not a number, return
      It seems, however, that this is basically a replacement for having the
      second offset
     */
    if ((line[i] > '9') || (line[i] < '0')) {
      break;
    }
    /* Add to buffer */
    *(numstr + bound) = line[i];
    bound++;
  }
  /* Add null terminator */
  *(numstr + bound) = '\0';
  ret = atoi(numstr);
  free(numstr);
  return ret;
}


/*
  Determine if the left or right mouse button is pressed
  Return 1 for right, 0 for left
 */
int leftright (char line[]) {
  int ret = 0;
  int i = 0;
  while (i < MAXLINESIZE) {
    if (line[i] == 'r') {
      return 1;
    }
    i++;
  }
  return ret;
}
