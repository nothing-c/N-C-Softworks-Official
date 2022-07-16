#include <windows.h>
#include <stdio.h>

/* Nab cursor position */

int main (void) {
  POINT pos;
  LPPOINT hold = &pos;
  //  bool yea = GetCursorPos(hold);
  GetCursorPos(hold);
  printf("%ld , %ld\n", hold->x, hold->y);
  return 0;
}
