#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ncurses/ncurses.h>
#include <unistd.h>

#define PI 3.14159
#define NUMCOLS 100
#define NUMROWS 72

#define AVATAR 'A'
#define WALL '*'
#define EMPTY_SPACE ' '

char MAZE[NUMROWS][NUMCOLS];

void generate_maze(int difficulty);
void draw_maze(void);
void draw_character(int x, int y, char use);
float calc_roll(float x_mag);

int main(int argc, char* argv[])
{
	if (argc <2) { printf("You forgot the difficulty\n"); return 1;}
	int difficulty = atoi(argv[1]); // get difficulty from first command line arg
	// setup screen    
	initscr();
	refresh();
	
	int x = 50;
	int y = 0;
	
	generate_maze(difficulty);
	draw_maze();
	draw_character(x, y, AVATAR);
	
	int t, b1, b2, b3, b4;
    double ax, ay, az, gx, gy, gz;
	int startTime = 0, endTime = 0, end = 0, flag = 0;
	
	do
	{
		
		scanf("%d, %lf, %lf, %lf, %lf, %lf, %lf, %d, %d, %d, %d", &t, &ax, &ay, &az, &gx, &gy, &gz, &b1, &b2, &b3, &b4 );
		

		startTime = t;
		
		//Moves the AVATAR down each time
		if(startTime - endTime > 500) //Is it time to move?
		{
			
			if(calc_roll(gx) > .2 && MAZE[y][x-1] != WALL && x - 1 >= 0) //Is the controller tilted to the left, and the next space not a wall (can we move left?
			{
				MAZE[y][x] = EMPTY_SPACE;
				x -= 1;
				draw_character(x,y,AVATAR);
				draw_character(x + 1, y, EMPTY_SPACE);
			}
			else if (calc_roll(gx) < -.2 && MAZE[y][x+1] != WALL && x + 1 <= 100)//Is the controller tilted to the right, and the next space not a wall (can we move right)?
			{
				MAZE[y][x] = EMPTY_SPACE;
				x += 1;
				draw_character(x,y,AVATAR);
				draw_character(x - 1, y, EMPTY_SPACE);
			}
			
			if(MAZE[y +1 ] [x] != WALL) //Is the next space not a wall?
			{
				y += 1;
				draw_character(x , y, AVATAR);
				draw_character(x, y-1, EMPTY_SPACE);
			}
			
			scanf("%d, %lf, %lf, %lf, %lf, %lf, %lf, %d, %d, %d, %d", &t, &ax, &ay, &az, &gx, &gy, &gz, &b1, &b2, &b3, &b4 );
			endTime = t;
		}
		
	}while(y < NUMROWS); // Are we still inside the screen?
	
	endwin();
	//Did the user win?
		printf("YOU WIN\n");


}

void draw_character(int x, int y, char use)
{
	mvaddch(y,x,use);    
	refresh();
}


void generate_maze(int difficulty)
{
	
	int i, j;
	for(i = 0 ; i < NUMROWS; i++)
	{
		for(j = 0; j < NUMCOLS; j++)
		{
			if(rand() % 100 >= difficulty)
			{
				MAZE[i][j] = EMPTY_SPACE;
			}
			else
			{
				MAZE[i][j] = WALL;
			}
			
		}
		
	}
}//End generate_maze function


void draw_maze()
{
	
	int i, j;
	for(i = 0; i < NUMROWS; i++)
	{
		for(j = 0; j < NUMCOLS; j++)
		{
			draw_character(j, i , MAZE[i][j]);
		}
	}
	
}


float calc_roll(float x_mag)
{
	
	if(x_mag < -1.0)
	{
		x_mag = -1.0;
	}
	else if (x_mag > 1.0)
	{
		x_mag = 1.0;
	}
	return asin(x_mag);
	
}


	