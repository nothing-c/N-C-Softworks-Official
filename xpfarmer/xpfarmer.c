/*
     ###         ###       #########  ###########     ##########   #########  #############
    ######      ###       ###        ###             ###    ###   ###             ###
   ###  ###    ###       ###          ##########    ###    ###   ########        ###
  ###    ###  ###  ###  ###                   ###  ###    ###   ###             ###
 ###      ######       ###                   ###  ###    ###   ###             ###
###        ###        ###########  ###########   ##########   ###             ###

*/

/* N-C Softworks CMDLINE XP Farmer, v0.1 (alpha)
	 Usage: fun game :)
	 Notes: resets every session
*/

/* TODO: first level works fine, but then lvlcalc doesn't hit and needed xp defaults to 1*/


#include <stdio.h>
#include "lvlup.h"

int counter();
void lvlup(int xp, int neededxp);
int lvlcalc(int neededxp);

struct level currentlevel;

int main(void){
	/* c for counting, xp for keeping track of XP */
	int c, neededxp, xp = 0;
	/* Setting starting level variables */
	currentlevel.neededxp = LVLONE;
	currentlevel.lvlnum = 0;
	neededxp = currentlevel.neededxp;
	printf("Welcome to XP Farmer by N-C Softworks\n");
	printf("Press any key to generate XP, and enter to check your XP and level up");
	counter(neededxp, 0);
	return 0;
}

int counter(int neededxp, int curxp){
	int c, xp = curxp;
	c = getchar();
	if (c == '\n'){
		lvlup(xp, neededxp);
	} else {
		xp++;
		counter(neededxp, xp);
	}
	return 0;
}

void lvlup(int xp, int neededxp){
	int tmp;
	if (xp >= neededxp){
		currentlevel.lvlnum += 1;
		currentlevel.neededxp = lvlcalc(neededxp);
		printf("You've leveled up!\n");
		printf("Your current level is: %u\n", currentlevel.lvlnum);
		/* Repeat until out of levelups */
		lvlup(xp, currentlevel.neededxp);
	} else {
		tmp = (currentlevel.neededxp - xp);
		printf("You need: %u XP to level up\n", tmp);
		counter(currentlevel.neededxp, xp);
	}
	counter(currentlevel.neededxp, xp);
}

int lvlcalc(int neededxp){
	return neededxp*10;
}
