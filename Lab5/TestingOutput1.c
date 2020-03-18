#include <stdio.h>
#include <math.h>

double mag( double x, double y, double z);
int close_to (double tolerance, double point, double value);

int main()
{
	int t, b1, b2, b3, b4;
    double ax, ay, az, gx, gy, gz;
	//scanf("%d, %lf, %lf, %lf, %lf, %lf, %lf, %d, %d, %d, %d", &t, &ax, &ay, &az, &gx, &gy, &gz, &b1, &b2, &b3, &b4 );
	
	printf("Shounak Lahiri\n");
	printf("sbalhiri\n");
	
	printf("Ok, now I am receiving data\n");
	printf("I'm waiting\n");
	
	while(1)
	{
		scanf("%d, %lf, %lf, %lf, %lf, %lf, %lf, %d, %d, %d, %d", &t, &ax, &ay, &az, &gx, &gy, &gz, &b1, &b2, &b3, &b4 );
		printf("Time = %d    Magnitude: %lf\n", t, mag(ax, ay, az));

	}
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

