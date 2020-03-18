#include <stdio.h>
#include <math.h>

/*
Function Prototype
*/
int numPressed(int tri, int circ, int x, int sqr);

void main()
{
	//printf("%d Buttons Are Pressed Currently\n", numPressed(triangle, circle, x, square));
	int triangle, circle, x, square;
	
	/*
	Instantiating Variables
	*/
		triangle= 0;
		circle=0;
		x=0;
		square=0;
		
	/*Loops to add 1 to the value*/
	
		for(int i=0; i<= 4; i++)
		{
			triangle = 1;
			printf("%d Buttons Are Pressed Currently\n", numPressed(triangle, circle, x, square));
		}
		
		for(int k=0; k<=4; k++)
		{
			circle = 1;
			printf("%d Buttons Are Pressed Currently\n", numPressed(triangle, circle, x, square));	
		}
		
		for(int h=0; h<=4; h++)
		{
			x = 1;
			printf("%d Buttons Are Pressed Currently\n", numPressed(triangle, circle, x, square));
		}
		
		for(int m = 0; m<= 4; m++)
		{
			square = 1;
			printf("%d Buttons Are Pressed Currently\n", numPressed(triangle, circle, x, square));
		}

		
		for( int e=0; e <= 19; e++)
		{
			if(e<=9)
			{
			 	triangle= 1;
				circle=0;
				x=1;
				square=0;
				printf("%d Buttons Are Pressed Currently\n", numPressed(triangle, circle, x, square));
			}
			else if (e < 15)
			{
				triangle= 1;
				circle=1;
				x=1;
				square=0;
				printf("%d Buttons Are Pressed Currently\n", numPressed(triangle, circle, x, square));				
			}
			else
			{
				triangle= 0;
				circle=0;
				x=0;
				square=1;
				printf("%d Buttons Are Pressed Currently\n", numPressed(triangle, circle, x, square));
			}
		}
		
		
}



int numPressed(int tri, int circ, int x, int sqr)
{
	int num =tri + circ + x + sqr;
	return num;
}