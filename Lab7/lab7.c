// 185 Lab 7
#include <stdio.h>


#define MAXPOINTS 10000

// compute the average of the first num_items of buffer
double avg(double buffer[], int num_items);

//update the max and min of the first num_items of array
void maxmin(double array[], int num_items, double* max, double* min);

//shift length-1 elements of the buffer to the left and put the 
//new_item on the right.
void updatebuffer(double buffer[], int length, double new_item);



int main(int argc, char* argv[]) {
	
	/* DO NOT CHANGE THIS PART OF THE CODE */

	double x[MAXPOINTS], y[MAXPOINTS], z[MAXPOINTS];
	int lengthofavg = 0;
	if (argc>1) {
		sscanf(argv[1], "%d", &lengthofavg );
		printf("You entered a buffer length of %d\n", lengthofavg);
	}
	else {
		printf("Enter a length on the command line\n");
		return -1;
	}
	if (lengthofavg <1 || lengthofavg >MAXPOINTS) {
		printf("Invalid length\n");
		return -1;
	}


	
	/* PUT YOUR CODE HERE */
	int t, b1, b2, b3, b4, counter = 0, j = 0;
    double ax, ay, az, gx, gy, gz, max = 0, min = 0;
	scanf("%d, %lf, %lf, %lf, %lf, %lf, %lf, %d, %d, %d, %d", &t, &ax, &ay, &az, &gx, &gy, &gz, &b1, &b2, &b3, &b4 );
	
	int count = 0; 
	while(b4 != 1)
	{
		if(count < lengthofavg -1 ) //Filling the buffer
		{
			for(j= 0; j < lengthofavg; j++)
			{
				scanf("%d, %lf, %lf, %lf, %lf, %lf, %lf, %d, %d, %d, %d", &t, &ax, &ay, &az, &gx, &gy, &gz, &b1, &b2, &b3, &b4 );
				x[j] = gx;
				y[j] = gy;
				z[j] = gz;
				count = j;
			}
			printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
			int o = 0;
			for( o= 0; o < lengthofavg; o++)
			{
				printf("X: %lf\n Y: %lf\n Z: %lf\n", x[o], y[o], z[o]);
			}
			

			
			
			maxmin(x, lengthofavg , &max, &min);
			printf("X: max: %lf min: %lf\n", max, min);
			maxmin(y, lengthofavg, &max, &min);
			printf("X: max: %lf min: %lf\n", max, min);
			maxmin(z, lengthofavg, &max, &min);
			printf("X: max: %lf min: %lf\n", max, min);
			
			printf("X: avg: %lf\n",avg(x, lengthofavg));
			printf("Y: avg: %lf\n", avg(y, lengthofavg));
			printf("Z: avg: %lf\n", avg(z, lengthofavg));
			
		}
		
		scanf("%d, %lf, %lf, %lf, %lf, %lf, %lf, %d, %d, %d, %d", &t, &ax, &ay, &az, &gx, &gy, &gz, &b1, &b2, &b3, &b4 );
		updatebuffer(x, MAXPOINTS, gx);
		updatebuffer(y, MAXPOINTS, gy);
		updatebuffer(z, MAXPOINTS, gz);
		
		maxmin(x, lengthofavg , &max, &min);
		printf("X: max: %lf min: %lf\n", max, min);
		maxmin(y, lengthofavg, &max, &min);
		printf("Y: max: %lf min: %lf\n", max, min);
		maxmin(z, lengthofavg, &max, &min);
		printf("Z: max: %lf min: %lf\n", max, min);
			
		printf("X: avg: %lf\n",avg(x, lengthofavg));
		printf("Y: avg: %lf\n", avg(y, lengthofavg));
		printf("Z: avg: %lf\n", avg(z, lengthofavg));
		
	}
	
}

void maxmin(double array[], int num_items, double* max, double* min)
{
	
	int i;
	//*max = array[0];
	//*min = array[0];
	for(i = 0; i < num_items; i++)
	{
		if(*max < array[i])
		{
			*max = array[i];
		}
		if(*min > array[i])
		{
			*min = array[i];
		}
	}
	
}

void updatebuffer(double buffer[], int length, double new_item)
{
	
	int i;
	for(i = 0; i < length; i++)
	{
		buffer[i+1] = buffer[i];
	} 
	buffer[0] = new_item;
	
}

double avg(double buffer [], int num_items)
{
	
	int i;
	double sum = 0;
	for( i = 0; i < num_items; i++)
	{
		sum += buffer[i];
	}
	return sum/ num_items;
	
}

