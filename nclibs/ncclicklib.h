/*
     ###         ###       #########  ###########     ##########   #########  #############
    ######      ###       ###        ###             ###    ###   ###             ###
   ###  ###    ###       ###          ##########    ###    ###   ########        ###
  ###    ###  ###  ###  ###                   ###  ###    ###   ###             ###
 ###      ######       ###                   ###  ###    ###   ###             ###
###        ###        ###########  ###########   ##########   ###             ###
*/

/*
  N-C Softworks Win32 Mouse Movement and Clicking Library
  Contents: click(), hold(), release()
*/

#include <windows.h>

/*
  Generate a click at the specified coordinates
  input values: 0 for leftclick, 1 for rightclick
*/
void click (int x, int y, int button) {
  INPUT input;
  /* Make sure Windows knows we're using the mouse */
  input.type = INPUT_MOUSE;
  /* Set the mouse position pre-click */
  input.mi.dx = x;
  input.mi.dy = y;
  /* Set the mouseData to 0 since we're not using the scroll wheel */
  input.mi.mouseData = 0;
  /* Set which button we're using */
  if (button > 0) {
      input.mi.dwFlags = MOUSEEVENTF_RIGHTDOWN;
  } else {
    input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
  }
  /* We don't care about scheduling the clicks */
  input.mi.time = 0;
  input.mi.dwExtraInfo = 0;
  /* Send the click */
  SendInput(1,&input,sizeof(input));
  /* Raise the button up */
  if (button > 0) {
      input.mi.dwFlags = MOUSEEVENTF_RIGHTUP;
  } else {
    input.mi.dwFlags = MOUSEEVENTF_LEFTUP;
  }
  SendInput(1,&input,sizeof(input));
}

/* Make the mouse hold down a button */
void hold (int x, int y, int button) {
  INPUT input;
  input.mi.dx = x;
  input.mi.dy = y;
  input.mi.mouseData = 0;
  if (button > 0) {
      input.mi.dwFlags = MOUSEEVENTF_RIGHTDOWN;
  } else {
    input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
  }
  input.mi.time = 0;
  input.mi.dwExtraInfo = 0;
  /* Send the click */
  SendInput(1,&input,sizeof(input));
  /* The mouse stays down */
}

/* Release a hold() command */
void release (int x, int y, int button) {
  INPUT input;
  /* Most of this is the same as above */
  input.mi.dx = x;
  input.mi.dy = y;
  input.mi.mouseData = 0;
  if (button > 0) {
      input.mi.dwFlags = MOUSEEVENTF_RIGHTUP;
  } else {
    input.mi.dwFlags = MOUSEEVENTF_LEFTUP;
  }
  input.mi.time = 0;
  input.mi.dwExtraInfo = 0;
  SendInput(1,&input,sizeof(input));
}

