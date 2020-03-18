/*-----------------------------------------------------------------------------
-					         SE/CprE 185 Lab 04
-             Developed for 185-Rursch by T.Tran and K.Wang
-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
-	                            Includes
-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>



/*-----------------------------------------------------------------------------
-	                            Defines
-----------------------------------------------------------------------------*/


/*-----------------------------------------------------------------------------
-	                            Prototypes
-----------------------------------------------------------------------------*/
int Terminater(int btn);
int close_to(double tolerance, double point, double value);
int printer(int num);
/*-----------------------------------------------------------------------------
-							  Implementation
-----------------------------------------------------------------------------*/
int main(void) {
    int t, b1, b2, b3, b4;
    double ax, ay, az, gx, gy, gz;


    while (1) {
        scanf("%d, %lf, %lf, %lf, %lf, %lf, %lf, %d, %d, %d, %d", &t, &ax, &ay, &az, &gx, &gy, &gz, &b1, &b2, &b3, &b4 );

        /* printf for observing values scanned in from ds4rd.exe, be sure to comment or remove in final program */
        printf("Echoing output: %d, %lf, %lf, %lf, %lf, %lf, %lf, %d, %d, %d, %d \n", t, ax, ay, az, gx, gy, gz, b1, b2, b3, b4);

        /* It would be wise (mainly save time) if you copy your code to calculate the magnitude from last week
         (lab 3).  You will also need to copy your prototypes and functions to the appropriate sections
         in this program. */

        //printf("At %d ms, the acceleration's magnitude was: %f\n", t, mag(ax, ay, az));
		// tolerance = .3, point = -1.0 value = -.987
		
		if ( (close_to(.3, 1.0, gy)) == 1)
		{
			printf("TOP\n");
		}
		else if ((close_to(.3,-1.0, gy) ) == 1)
		{
			printf("BOTTOM\n");
		}
		else if ((close_to(.3, 1.0 ,gx)) == 1)
		{
			printf("RIGHT\n\n");
		}
		else if ((close_to(.3,-1.0, gx)) ==1)
		{
			printf("LEFT\n");
		}
		else if ((close_to(.3, 1.0, gz)) ==1)
		{
			printf("FRONT\n");
		}
		else if ((close_to(.3, -1.0, gz)) ==1)
		{
			printf("BACK\n");
		}
		else
		{
			printf("ERROR\n");
		}
    }

    return 0;
}

/* Put your functions here */


int Terminater(int btn)
{
	if(btn == 1)
	{
		exit(0);
	}
}

int close_to(double tolerance, double point, double value)
{
	if(abs(abs(point) - abs(value)) <= tolerance && abs(abs(point) - abs(value))>=0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
	
}
