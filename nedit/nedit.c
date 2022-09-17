/*
     ###         ###       #########  ###########     ##########   #########  #############
    ######      ###       ###        ###             ###    ###   ###             ###
   ###  ###    ###       ###          ##########    ###    ###   ########        ###
  ###    ###  ###  ###  ###                   ###  ###    ###   ###             ###
 ###      ######       ###                   ###  ###    ###   ###             ###
###        ###        ###########  ###########   ##########   ###             ###
*/
/* 
Append-only curses text editor
Use ^C to exit and ^H to backspace and overwrite
Saving is automatic
*/
typedef int I;
typedef char* S;
#include <curses.h>
#include <stdio.h>
typedef FILE* F;
#include <unistd.h>
#define W(x) while(true){x}
I main(I c, S v[]){I l=0;initscr();F f=fopen(v[1],"r");while(!feof(f)){I h=fgetc(f);addch(h);if(h=='\n'){l++;}};l++;W(F f=fopen(v[1], "ab+");I c=getch();fputc(c,f);if(c=='\n'){move(l++,0);}refresh();fclose(f);)return 0;}
