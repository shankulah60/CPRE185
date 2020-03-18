/*-----------------------------------------------------------------------------
-					          CPRE 185 Lab 02
-	Name: Shounak Lahiri
- 	Section: M
-	NetID: sblahiri
-	Date: 9/5/2018
-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
-	                            Includes
-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <math.h>


/*-----------------------------------------------------------------------------
-	                            Defines
-----------------------------------------------------------------------------*/


/*-----------------------------------------------------------------------------
-	                            Prototypes
-----------------------------------------------------------------------------*/


/*-----------------------------------------------------------------------------
-							 Implementation
-----------------------------------------------------------------------------*/

int main()
{
	int a, b, e, f, j;
	double c, d, g, h, i, k;
	
	a= 6427+ 1725;
	b= (6971 * 3925) - 95;
	c= 79+12 / 5;
	d= 3640.0 / 107.9;
	e= (22 / 3) * 3 ;
	f= 22 / (3 * 3);
	g= 22 / (3 * 3);
	h= 22 / 3* 3;
	i= (22.0 / 3) * 3.0;
	j= 22.0 / ( 3* 3.0);
	k= 22.0 / 3.0 * 3.0;
	
	printf("The calculation is: 6427+ 1725 = %d\n", a);
	printf("The calculation is: (6971 * 3925) - 95 = %d\n", b);
	printf("The calculation is: 79+12 / 5 = %.2lf\n", c);
	printf("The calculation is: 3640.0 / 107.9 = %.2lf\n", d);
	printf("The calculation is: (22 / 3) * 3 = %d\n", e);
	printf("The calculation is: 22 / (3 * 3) = %d\n", f);
	printf("The calculation is: 22 / (3 * 3) = %.2lf\n",g);
	printf("The calculation is: 22 / 3* 3 = %.2lf\n",h);
	printf("The calculation is: (22.0 / 3) * 3.0 = %.2lf\n", i);
	printf("The calculation is: 22.0 / ( 3* 3.0) = %d\n",j);
	printf("The calculation is: 22.0 / 3.0 * 3.0 = %.2lf\n", k);
	printf("\n");
	
	double circleArea, circumference= 23.567;
	circleArea= (circumference * circumference) / (4 * M_PI);
	printf("The area of a circle with a circumference of %lf is %lf units squared\n", circumference, circleArea);
	
	const double FEET_TO_METER= .3048;
	printf("One foot = %.4lf , 14 feet = %.4lf meters\n", FEET_TO_METER, 14.0 * FEET_TO_METER );
	
	double Far= 76.0;
	printf("76 degrees F = %.2lf degrees C", (Far-32.0)/1.8 );
	
	
	
	
	
	
	return 0;
}