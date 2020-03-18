#include <stdio.h>
#include <math.h>
#include <unistd.h>

double mag( double x, double y, double z);
int close_to (double tolerance, double point, double value);
int timePrinter (int t);
#define g 9.8

int main()
{
	int t, b1, b2, b3, b4;
    double ax, ay, az, gx, gy, gz, startTime, endTime, timeFall;
	scanf("%d, %lf, %lf, %lf, %lf, %lf, %lf, %d, %d, %d, %d", &t, &ax, &ay, &az, &gx, &gy, &gz, &b1, &b2, &b3, &b4 );
	
	printf("Shounak Lahiri\n");
	printf("sbalhiri\n");
	
	printf("Ok, now I am receiving data\n");
	printf("I'm waiting");
	

		scanf("%d, %lf, %lf, %lf, %lf, %lf, %lf, %d, %d, %d, %d", &t, &ax, &ay, &az, &gx, &gy, &gz, &b1, &b2, &b3, &b4 );
		while(close_to(.25, 1, mag(ax,ay,az)) == 1)
		{
			scanf("%d, %lf, %lf, %lf, %lf, %lf, %lf, %d, %d, %d, %d", &t, &ax, &ay, &az, &gx, &gy, &gz, &b1, &b2, &b3, &b4 );
			printf(".");
			fflush(stdout);
		}
		
		startTime = t;
		int fallState;
		double total;
		double vel;
		double fallTime;
		double seconds;
		int loopStart;
		int loopEnd;
		
		while(close_to(.25, 1, mag(ax,ay,az)) == 0)
		{
			loopStart = t;
			scanf("%d, %lf, %lf, %lf, %lf, %lf, %lf, %d, %d, %d, %d", &t, &ax, &ay, &az, &gx, &gy, &gz, &b1, &b2, &b3, &b4 );
			if(fallState == 0)
			{
				printf("\n Help me, I'm Falling");
				fallState = 1;
			}
			else
			{
				printf("!");
			}

			loopEnd = t;
			fallTime = loopEnd - loopStart;
			seconds = fallTime/ 1000.00;
			vel  += (g) * (1-mag(ax,ay,az)) * (seconds);
			total += vel * seconds;			
		}
				
		printf("\n");		
		endTime = t;
		
		double TimeFallen = (endTime - startTime)/1000;		
		double distance = (0.5 * g * TimeFallen * TimeFallen);
		double percentLess = (1 - (total/distance)) * 100;
		printf("Ouch! I fell %lf meters in %lf seconds.\n", distance , TimeFallen);
		printf("Compensating for air resistance, the fall distance was %lf\n" , total);
		printf("This is %.2lf", percentLess);
		printf("%% than before.");
		fflush(stdout);
}

double mag(double x, double y, double z)
{
	double value= pow(x,2) + pow(y,2) + pow(z,2);
	return sqrt(value);	
}

int close_to(double tolerance , double point, double value)
{
	double difference;
	difference = fabs(point - value);
	if (difference <= tolerance) 
	{
		return 1;
	}
	else
	{
		return 0;
	}
	
}

int timePrinter(int t)
{
	if(t%1000 == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
	
}