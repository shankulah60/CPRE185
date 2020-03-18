/* 185 Lab 3 Template */

#include <stdio.h>
#include <math.h>

/* Put your function prototypes here */
int numPressed(int tri, int circ, int x, int sqr);

int main(void) {
    /* DO NOT MODIFY THESE VARIABLE DECLARATIONS */
    int t;
    double  ax, ay, az;     


    /* This while loop makes your code repeat. Don't get rid of it. */
    while (1) {
        
				int triangle, circle, x, square;
				scanf(" %d , %d , %d , %d " ,&triangle , &circle, &x , &square);
				printf("%d Buttons Are Pressed Currently\n", numPressed(triangle, circle, x, square));
				fflush(stdout);

    }

return 0;
}

/* Put your functions here */


int numPressed(int tri, int circ, int x, int sqr)
{
	int num =tri + circ + x + sqr;
	return num;
}


