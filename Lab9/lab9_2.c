// Lab 9 DS4Talker Skeleton Code

/*
	Possibe Problems
		- Pointer to change the number of rows and columns
		- Adjust the values for out of screen in the moving if statement
		- What are the joysticks
		

*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <curses.h>
#define MAXWORDS 100 
#define DEBUG 1   // set to 0 to disable debug output
#define CURSOR 'A'

// reads words from the file
// into wl and trims the whitespace off of the end of each word
// DO NOT MODIFY THIS Prototype
int readWords(char* wl[MAXWORDS], char* filename); 

// modifies s to trim white space off the right side
// DO NOT MODIFY THIS Prototype
void trimws(char* s);
void draw_character(int x, int y, char use);
void changeX(int *x, int *y);
int screenToIndex(int x, int y);
void clearWord(char word[]);

int main(int argc, char* argv[]) {
	char* wordlist[MAXWORDS];
	int wordCount;
	int i;
	wordCount = readWords(wordlist, argv[1]) - 1;

	if (DEBUG) {
		printf("Read %d words from %s \n", wordCount, argv[1]);
			for (int i = 0; i < wordCount; i++){
				printf("%s\n", wordlist[i]);
			}
		}

// most of your code for part 2 goes here. Don't forget to include the ncurses library 
	initscr();
	
	int x = 0, y = 0;
	for( i = 0; i < wordCount; i++)
	{
		
		mvprintw(y, x, "%s", wordlist[i]);
		refresh();
		x += 15;
		changeX(&x, &y);
	}
	
	int row = wordCount / 5; //Number of rows
	if((wordCount % row) != 0) //Adding 1 in case the list of words are not divisible by 5
	{
		row += 1;
	}
	
	int t, jLH, jLV, jRH, jRV, bT, bC, bX, bS;
	int nowX = 0; nowY = 0, lastX = 0;, lastY = 0, index = 0;
	int updatedTime = 0;
	int lastLen = 0, senLen = 0, cap = 0;;
	char currWord[12];
	
	do
	{
		
		scanf("%d, %d, %d, %d, %d, %d, %d, %d, %d", &t, &bT, &bC, &bX, &bS, &jLH ,&jLV, &jRH, &jRV);
		//Time condition
		draw_character(lastX, lastY, ' ');
		//Changing the coordinates based on the right joystick movement
		if((jRV < 0) && (nowY < row - 1)) //May have to adjust the values
		{
			nowY += 1;
		}
		else if((jRV > 0) && (nowY > 0))
		{
			noyY -= 1;
		}
		
		if((jRH > 0) && (nowX < 60)) //having 60 makes sure that the movement is valid
		{
			nowX += 15;
		}
		else if ((jRH < 0) && (nowX > 0))
		{
			nowX -= 15;
		}
		
		lastX = nowX;
		lastY = nowY;
		draw_character(nowX, nowY, CURSOR);
		
		//Checking if the buttons are pressed
		if(bT == 1)
		{
			index = screenToIndex(nowX, nowY);
			lastLen = strlen(wordlist[index]) + 1;
			strcpy(currWord, wordlist[index]);
			if(cap == 1)
			{
				currWord[0] = toupper(currWord[0]);
				cap = 0;
			}
			mvprintw(row + 2, senLen, "%s", currWord);
			senLen += lastLen;
			clearWord(currWord);
		}
		else if(bS == 1)
		{
			index = screenToIndex(nowX, nowY);
			lastLen = strlen(wordlist[index]);
			strcpy(currWord, wordlist[index]);
			if(cap == 1)
			{
				currWord[0] = toupper(currWord[0]);
				cap = 0;
			}
			mvprintw(row + 2, senLen, "%s", currWord);
			senLen += lastLen;
			clearWord(currWord);
		}
		else if(bX == 1)
		{
			index = screenToIndex(nowX, nowY);
			senLen -= lastLen;
			mvprintw(row + 2, senLen, "");
		}
		else if(bC == 1)
		{
			cap = 1;
		}
		
	}while(1);
	
	endwin();
	
    return 0;
	}
	
	
	

int readWords(char* wl[MAXWORDS], char* filename){
	int num = 0;
	char line[10];
	char *p;
	FILE* f = fopen(filename,"r");
	while (!feof(f)) {
		fgets(line, 10, f);
		if (!feof(f) && p != NULL) {
			trimws(line);
			wl[num] = (char *)  malloc(strlen(line));
			strcpy(wl[num], line);
			num++;
			}
		} 
	fclose(f);
	return num;
}

void trimws(char* s)
{
        int x;
        x = strlen(s) - 1;
        while (isspace(s[x]) && (x>=0)) 
		{
            s[x] = '\0';
            x -= 1;
        }
}

void draw_character(int x, int y, char use)
{
        mvaddch(y,x,use);    
        refresh();
}

void changeX(int *x, int *y)
{
	
	if(*x >= (15*5))
	{
		*y += 1;
		*x = 0;
	}
	
}
int screenToIndex(int x, int y)
{
	return (y*5) + (x/15);
}

void clearWord(char word[])
{
	int i;
	for(i =0; i < 12; i++)
	{
		word[i] = ' ';
	}
}