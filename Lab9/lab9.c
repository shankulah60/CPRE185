// Lab 9 DS4Talker Skeleton Code

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define MAXWORDS 100 
#define DEBUG 1   // set to 0 to disable debug output

// reads words from the file
// into wl and trims the whitespace off of the end of each word
// DO NOT MODIFY THIS Prototype
int readWords(char* wl[MAXWORDS], char* filename); 

// modifies s to trim white space off the right side
// DO NOT MODIFY THIS Prototype
void trimws(char* s);

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