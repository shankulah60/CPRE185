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

// Use
// ./ds4rd.exe -d 054c:05c4 -D DS4_BT -t -a -b | ./lab7.exe
// to run

int main(int argc, char* argv[]) {
	
	/* DO NOT CHANGE THIS PART OF THE CODE */

	double x[MAXPOINTS], y[MAXPOINTS], z[MAXPOINTS];
	int lengthofavg = 0;
	if (argc > 1) {
		sscanf(argv[1], "%d", &lengthofavg );
		printf("You entered a buffer length of %d\n", lengthofavg);
	}
	else {
		printf("Enter a length on the command line\n");
		return -1;
	}
	if (lengthofavg < 1 || lengthofavg > MAXPOINTS) {
		printf("Invalid length\n");
		return -1;
	}
	
	int t, counter;
	int b_Triangle, b_Circle, b_X, b_Square;
	double gx, gy, gz, avg_x, avg_y, avg_z, xmin, xmax, ymin, ymax, zmin, zmax;

	counter = 0;

	if(lengthofavg < 1) {
		printf("Please enter a buffer value: ");
		scanf("%d", &lengthofavg);
	}
	do {
		// scanf("%d, %lf, %lf, %lf, %d, %d, %d, %d, %d, %d", &t, &gx, &gy, &gz, &b[0], &b[1], &b[2], &b[3], &b[4], &b[5]);
		scanf("%d, %lf, %lf, %lf, %d, %d, %d, %d", &t, &gx, &gy, &gz, &b_Triangle, &b_Circle, &b_X, &b_Square);
		updatebuffer(x, lengthofavg, gx);
		updatebuffer(y, lengthofavg, gy);
		updatebuffer(z, lengthofavg, gz);
		
		avg_x = avg(x, lengthofavg);
		avg_y = avg(y, lengthofavg);
		avg_z = avg(z, lengthofavg);

		xmax = 0;
		xmin = 0;
		ymax = 0;
		ymin = 0;
		zmax = 0;
		zmin = 0;
		
		maxmin(x, lengthofavg, &xmax, &xmin);
		maxmin(y, lengthofavg, &ymax, &ymin);
		maxmin(z, lengthofavg, &zmax, &zmin);

		if (counter > lengthofavg){
		printf("%lf, %lf, %lf || %lf, %lf, %lf || x %lf, %lf || y %lf, %lf || z %lf, %lf\n", gx, gy, gz, avg_x, avg_y, avg_z, xmin, xmax, ymin, ymax, zmin, zmax);
		}

		counter++;

		// printf("%lf, %lf, %lf\n", avg_x, avg_y, avg_z);
		
		fflush(stdout);
	} while(b_Square != 1);

	
}

double avg(double buffer[], int num_items) {
	double avg = 0;
	int i;
	for(i = 0; i < num_items; i++) {
		avg += buffer[i];
	}
	avg = avg / (double)num_items;
	return avg;
}

void maxmin(double array[], int num_items, double* max, double* min) {
	int i;
	for(i = 0; i < num_items; i++) {
		if(array[i] > *max) {
			*max = array[i];
		}
		if(array[i] < *min) {
			*min = array[i];
		}
	}
}

void updatebuffer(double buffer[], int length, double new_item) {
	int i;
	for(i = 0; i < length-1; i++) {
		buffer[i] = buffer[i + 1];
	}
	buffer[length - 1] = new_item;
}