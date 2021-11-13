/*
     ###         ###       #########  ###########     ##########   #########  #############
    ######      ###       ###        ###             ###    ###   ###             ###
   ###  ###    ###       ###          ##########    ###    ###   ########        ###
  ###    ###  ###  ###  ###                   ###  ###    ###   ###             ###
 ###      ######       ###                   ###  ###    ###   ###             ###
###        ###        ###########  ###########   ##########   ###             ###

*/

/* N-C Softworks CMDLINE XP Farmer Header File
	 Contains: levelup phrases and levels
*/

/* File editable to customize your game :) */

#define LVLONE 10
#define CREATOR_NAME "Nothing-C"

/* Calculates new next level */
#define LVLCALC(current) (current * 10)

/* Level struct - neededxp == how much xp til lvlup */
typedef struct level{
	int neededxp, lvlnum;
} level;
