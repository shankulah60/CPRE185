/*-----------------------------------------------------------------------------
-					          CPRE 185 Lab 02
-	Name:
- 	Section:
-	NetID:
-	Date:
-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
-	                            Includes
-----------------------------------------------------------------------------*/
#include <stdio.h>


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
    int integerResult;
    double decimalResult;

    decimalResult = 77 / 5;
    printf("The value of 77/5 is %lf, using integer math\n", decimalResult);
	/* 
	   Changed from integerResult to decimalResult so that the compiler outputs the value for
	   the variable at the %d location in the printf statement. 
	*/

    integerResult = 2 + 3;
    printf("The value of 2+3 is %d\n", integerResult);
	/*
	   Added the variable integerResult so that the printf statement outputs the value
	   of the variable integerResult at the %d location in the statement.
	
	*/

    decimalResult = 1.0 / 22.0;
    printf("The value 1.0/22.0 is %lf\n", decimalResult);
	/*
	   Changed %d to %lf because the variable decimalResult is defined as a double
	   not an integer.
	*/

    return 0;
}
/*

*/


