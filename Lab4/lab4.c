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
double mag( double x, double y, double z);
int close_to (double tolerance, double point, double value);
int ButtonTest ( int button);


/*-----------------------------------------------------------------------------
-							  Implementation
-----------------------------------------------------------------------------*/
int main(void) 
{
    int t, b1, b2, b3, b4;
    double ax, ay, az, gx, gy, gz;


    while (1) 
	{
        scanf("%d, %lf, %lf, %lf, %lf, %lf, %lf, %d, %d, %d, %d", &t, &ax, &ay, &az, &gx, &gy, &gz, &b1, &b2, &b3, &b4 );

        /* printf for observing values scanned in from ds4rd.exe, be sure to comment or remove in final program */
        // printf("Echoing output: %d, %lf, %lf, %lf, %lf, %lf, %lf, %d, %d, %d, %d \n", t, ax, ay, az, gx, gy, gz, b1, b2, b3, b4);

        /* It would be wise (mainly save time) if you copy your code to calculate the magnitude from last week
         (lab 3).  You will also need to copy your prototypes and functions to the appropriate sections
         in this program. */

        //printf("At %d ms, the acceleration's magnitude was: %f\n", t, mag(ax, ay, az));

		//Terminates Program if the triangle button is pressed.
		if(ButtonTest(b1) == 1)
		{
			exit(0);
		}
		
		
		
		if(close_to(.005, 1.0 , gy) == 1)
		{
			printf("TOP\n");
		}
		else if (close_to(.005, -1.0 , gy) == 1)
		{
			printf("BOTTOM\n");
		}
		else if (close_to(.005, 1.0, gx) == 1)
		{
			printf("RIGHT\n");
		}
		else if (close_to(.005, -1.0 , gx) == 1)
		{
			printf("LEFT\n");
		}
		else if (close_to(.005, 1.0, gz) == 1)
		{
			printf("BACK\n");
		}
		else if (close_to(.005, -1.0, gz)== 1)
		{
			printf("FRONT\n");
		}
		
		
		
		
		
		/*if (close_to(.3, 0.0 , gx) && close_to(.3, 0.0, gz) && close_to(.3, 1.0, gy))
		{
			printf("TOP\n");
		}
		 else if (close_to(.3, 0.0 , gx) && close_to(.3, 0.0, gz) && close_to(.3, -1.0, gy))
		{
			printf("BOTTOM\n");
		}
		 else if (close_to(.3, 1.0 , gx) && close_to(.3, 0.0, gz) && close_to(.3, 0.0, gy))
		{
			printf("RIGHT\n");
		}
		 else if (close_to(.3, -1.0 , gx) && close_to(.3, 0.0, gz) && close_to(.3, 0.0, gy))
		{
			printf("LEFT\n");
		}
		 else if (close_to(.3, 0.0 , gx) && close_to(.3, 1.0, gz) && close_to(.3, 0.0, gy))
		{
			printf("BACK\n");
		}
		 else if (close_to(.3, 0.0 , gx) && close_to(.3, -1.0, gz) && close_to(.3, 0.0, gy))
		{
			printf("FRONT\n");
		}*/
		
	fflush(stdout);	
    }

    return 0;
}

/* Put your functions here */

double mag(double x, double y, double z)
{
	double value= pow(x,2) + pow(y,2) + pow(z,2);
	return sqrt(value);
	
}

int close_to (double tolerance , double point, double value)
{
	
	if ( (abs(point-value) <= tolerance) || ( ((abs(point) + tolerance) - abs(value)) <= tolerance))
	{
		return 1;
	}
	else
	{
		return 0;
	}
	

}

int ButtonTest( int btn1)
{
	if (! btn1 == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
	
}


