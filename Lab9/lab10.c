// Lab 10 ExTalker Skeleton Code

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define MAXWORDS 100
#define WORDLEN 11
#define DEBUG 0   // set to 0 to disable debug output

int readWords(char *wl[MAXWORDS], char* filename); // reads words from the file
// into wl and trims the whitespace off of the end

//modifies s to trim white space off the right side
void trimws(char* s) ;

// PRE: 0 < x < WIDTH, 0 < y < HEIGHT, 0 < use < 255
// POST: Draws character use to the screen and position x,y
void draw_character(int x, int y, char use);

int main(int argc, char* argv[]) {
        char* wordlist[MAXWORDS];
        int wordCount;
        int i;
        wordCount = readWords(wordlist, argv[1]);

        if (DEBUG) 
		{
            printf("Read %d words from %s \n",wordCount, argv[1]);
            for (i = 0; i< wordCount; i++) {
                printf("%s,", wordlist[i]);

            }
            printf("\n");
        }
 

	//start ncurses
	initscr();
    refresh();
	
	//build the word table
	int xVal = 0, yVal = 0;
	for(i = 0; i < wordCount; i++)
	{
		mvprintw(yVal, xVal, " %s", wordlist[i]);
		refresh();
		xVal += 15;
		if(xVal >= 75) 
		{
			yVal++;
			xVal = 0;
		}	
	}

	//calculate row count
	int rowCount = wordCount / 5;
	if(wordCount%rowCount != 0 ) rowCount ++;
	
	//start loop
	int time, joyDown, joyUp, joyLeft, joyRight, joy5, joy6;
	int b1, b2, b3, b4, b5, b6;
	int curX = 0, curY = 0;
	int prevX = 0, prevY = 0;
	int moveTime = 0;
	int lengthOfLast = 0;
	int lengthOfSentance = 0;
	int capitalizeNext = 0;
	
	do
	{
		
		//get joystick values and assign joyX and joyY
		scanf("%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d", 
				&time, &b1, &b2, &b3, &b4, &b5, &b6, &joyDown, &joyUp, &joyLeft, &joyRight, &joy5, &joy6);
		//mvprintw(20,0,"%d", b5); // debug
		
		if(time - moveTime < 300)
		{
			//too soon, wait
			continue;
		}
		
		//delete previous cursor
		draw_character(prevX, prevY, ' ');
		
		//reassign the curX and curY accordingly
		if(joyDown && curY < rowCount-1)
		{
			curY++;
		}
		else if(joyUp && curY>0)
		{
			curY--;
		}
		
		if(joyRight && curX < 60)	
		{
			curX+=15;
		}
		else if(joyLeft && curX > 0)
		{
			curX-=15;
		}
		
		// new cursor position
		moveTime = time;// capture for delay
		
		prevX = curX;
		prevY = curY;
		
		//draw new cursor
		draw_character(curX, curY, '-');
		
		// see if user wishes to select and select

		if(b2)// add selected with space
		{
			int indexToUse = curY*5 + curX/15;
			lengthOfLast = strlen(wordlist[indexToUse])+1;
			
			char toAdd[12];
			strcpy(toAdd, wordlist[indexToUse]);
			if(capitalizeNext)
			{
				toAdd[0] -= 0x20;
			}
			mvprintw(rowCount+2, lengthOfSentance," %s", toAdd);
			lengthOfSentance += lengthOfLast;
		}
		else if(b3) // add selected without space
		{
			int indexToUse = curY*5 + curX/15;
			lengthOfLast = strlen(wordlist[indexToUse]);
			char toAdd[12];
			strcpy(toAdd, wordlist[indexToUse]);
			if(capitalizeNext)
			{
				toAdd[0] -= 0x20;
			}
			mvprintw(rowCount+2, lengthOfSentance,"%s", toAdd);
			lengthOfSentance += lengthOfLast;
		}
		else if(b4) // add selected with capitalized first letter
		{
			if(capitalizeNext)
			{
				capitalizeNext = 0;
				mvprintw(rowCount+1, 0,"    ");
			}
			else 
			{
				capitalizeNext = 1;
				mvprintw(rowCount+1, 0,"CAP");
			}
			
		}
		else if(b1) // delete last added
		{
			int indexToUse = curY*5 + curX/15;
			lengthOfSentance -= lengthOfLast;
			mvprintw(rowCount+2,lengthOfSentance,"              "); // debug
			
		}
		
	}
	while(1);
	endwin();

}

void trimws(char* s) {
        int len = strlen(s) ;
        int x;
        if (len ==0) return;
        x = len-1;
        while (isspace(s[x]) && (x>=0)) {
                s[x] = '\0';
                x--;
                }
}



int readWords(char* wl[MAXWORDS], char* filename) {
        int numread =0;
        char line[WORDLEN];
        char *p;
        FILE* fp = fopen(filename,"r");
        while (!feof(fp)) {
                p  =fgets(line, WORDLEN, fp);
                if (!feof(fp) && p !=NULL) {
                        trimws(line);
                        wl[numread] = (char *)  malloc(strlen(line)+1);
                        strcpy(wl[numread], line);
                        numread++;
                        }
                } 
    fclose(fp);
    return numread; 
}

// PRE: 0 < x < WIDTH, 0 < y < HEIGHT, 0 < use < 255
// POST: Draws character use to the screen and position x,y
//THIS CODE FUNCTIONS FOR PLACING THE AVATAR AS PROVIDED.
//YOU DO NOT NEED TO CHANGE THIS FUNCTION.
void draw_character(int x, int y, char use)
{
        mvaddch(y,x,use);    
        refresh();
}