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

	//My Variables
	int t, b1, b2, b3, b4, counter = 0;
    double ax, ay, az, gx, gy, gz;
	double max_x = 0, min_x = 0, max_y = 0, min_y = 0, max_z = 0, min_z = 0, avg_x = 0, avg_y = 0, avg_z = 0;
	
	while(b4 != 1)
	{
		//Get new values
		scanf("%d, %lf, %lf, %lf, %lf, %lf, %lf, %d, %d, %d, %d", &t, &ax, &ay, &az, &gx, &gy, &gz, &b1, &b2, &b3, &b4 );
		
		//Fill the respective arrays with new values
		updatebuffer(x, lengthofavg , gx);
		updatebuffer(y, lengthofavg , gy);
		updatebuffer(z, lengthofavg , gz);
		
		if(counter > lengthofavg)
		{
			
			//Calculate the average for each
			avg_x = avg(x, lengthofavg);
			avg_y = avg(y, lengthofavg);
			avg_z = avg(z, lengthofavg);
			
			//Find the Max/Min for each
			maxmin(x, lengthofavg, &max_x, &min_x);
			maxmin(y, lengthofavg, &max_y, &min_y);
			maxmin(z, lengthofavg, &max_z, &min_z);
			
			//Print the result for CSV file
			printf("%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf\n", gx, gy, gz, avg_x, avg_y, avg_z, max_x, min_x, max_y, min_y, max_z, min_z);
			
		}
		
		counter++;
		fflush(stdout);
	}//End of while
	



}//End of main


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
	
}//End of maxmin


void updatebuffer(double buffer[], int length, double new_item)
{
	
	int i;
	for(i = 0; i < length; i++)
	{
		buffer[i+1] = buffer[i];
	} 
	buffer[0] = new_item;
	
}//End of updatebuffer


double avg(double buffer [], int num_items)
{
	
	int i;
	double sum = 0;
	for( i = 0; i < num_items; i++)
	{
		sum += buffer[i];
	}
	return sum/ num_items;
	
}//End of avg

