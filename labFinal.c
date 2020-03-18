#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <curses.h>
#define MAXWORDS 100
#define WORDLEN 11
#define DEBUG 0 
#define CURSOR '>'

//Function Prototypes
int readWords(char *wl[MAXWORDS], char* filename); 
void trimws(char* s) ;
int screenX(int index);
int screenY(int index);
int screenToIndex(int y, int x);
void draw_character(int x, int y, char use);

int main(int argc, char* argv[]) {
        char* wordlist[MAXWORDS];
        int numWords;
        int i;
        numWords = readWords(wordlist, argv[1]);

        if (DEBUG) 
		{
            printf("Read %d words from %s \n",numWords, argv[1]);
            for (i = 0; i< numWords; i++) {
                printf("%s,", wordlist[i]);

            }
            printf("\n");
        }
 

	
	
	int tempX = 0, tempY = 0, rows = 0;
	initscr();
	
	for(i = 0; i < numWords; i++)
	{
		tempX = screenX(i);
		tempY = screenY(i);
		mbbprintw(tempY, tempX, "%s", wordlist[i]);
	}

	rows = numWords / 5; //calcualting the number of rows
	
	if(numWords % rows != 0 ) 
	{
		rows += 1; //Adding a row if there are more than an even number of rows (divisible by 5)
	} 
	
	int time, jLH, jLV, jRH, jRV, bT, bC, bX, bS;
	int nowX = 0, nowY = 0, lastX = 0, lastY = 0;
	int lastLen = 0, senLen = 0;
	
	do
	{
		scanf("%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d", &time, &bT, &bC, &bX, &bS, &jRD, &jLD, &option, &share, &R2, &L2, &R1, &L1, &jLH, &jLV, &jRH, &jRV);
		
		
		draw_character(lastX, lastY, ' ');//Remove the last cursor 
		
		//Control the movement with the joysticks
		if(((jRV > 20)||(jLV > 20)) && nowY < rows-1)
		{
			nowY++;
		}
		else if(((jRV < -20)||(jLV < -20)) && nowY>0)
		{
			nowY--;
		}
		else if(((jRH > 20)|| (jLH > 20)) && nowX < 60)	
		{
			nowX+=15;
		}
		else if(((jRH < -20)||(jLH < -20)) && nowX > 0)
		{
			nowX-=15;
		}//end movement if
		
		//Update location for replacing in next iteration
		lastX = nowX;
		lastY = nowY;
		
		draw_character(nowX, nowY, CURSOR); //Draw cursor at new spot
		

		if(bT == 1)//Add with space
		{
			index = screenToIndex(nowY, nowX);
			lastLen = strlen(wordlist[index])+1;
			
			char addWord[12];
			strcpy(addWord, wordlist[index]);
			mvprintw(rows + 2, senLen," %s", addWord);
			senLen += lastLen;
		}
		else if(bS == 1) //Add without space
		{
			index = screenToIndex(nowY, nowX);
			lastLen = strlen(wordlist[index]);
			char addWord[12];
			strcpy(addWord, wordlist[index]);
			mvprintw(rows + 2, senLen,"%s", addWord);
			senLen += lastLen;
		}
		else if(bX == 1) //Undo the last operation
		{
			index = screenToIndex(nowY, nowX);
			senLen -= lastLen;
			mvprintw(rows + 2, senLen ,"              ");
		}//end button if
		
	}while(1);
	endwin();

}//end main 

//Reads in words from text file
int readWords(char* wl[MAXWORDS], char* filename)
{
	int num = 0; //Number of words 
	char word[10]; //Temporary words
	char *p;
	FILE* f = fopen(filename,"r");
	while (feof(f) != 0) 
	{
		fgets(word, 10, f);
		if (p != NULL) 
		{
			trimws(word);
			wl[num] = (char *)  malloc(strlen(word));
			strcpy(wl[num], word);
			num += 1;
		}
	} 
	return num;
}//end readWords

//Gets rid of white space characters
void trimws(char* s)
{
        int in;
        in = strlen(s) - 1;
        while ((isspace(s[in])) && (in >= 0)) 
		{
            s[in] = '\0';
            x -= 1;
        }
}//end trimws

int screenY(int index)
{
	int y = index / 5;
	return y;
}

int screenX(int index)
{
	
	int modFive = index % 5;
	int x = modFive * 15;
	return x;
}

int screenToIndex(int y, int x)
{
	int normalX = x / 15;
	int normalY = y * 5;
	int index = normalX + normalY;
	return index;
}

void draw_character(int x, int y, char use)
{
        mvaddch(y,x,use);    
        refresh();
}

