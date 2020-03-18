#include <stdio.h>
#include <math.h>
#define PI 3.141592653589
#define ROLL 0
#define PITCH 1
#define TRUE 1
#define FALSE 0


int read_line(double* g_x, double* g_y, double* g_z, int* time, int* Button_T, int* Button_C, int* Button_X, int* Button_S);
double roll(double x_mag);
double pitch(double y_mag);
int scaleRadsForScreen(double rad);
void print_chars(int num, char use);
void graph_line(int number);


int main()
{
	
	int time;
	double a_x, a_y, a_z;
	double g_x, g_y, g_z;
	int Button_T, Button_C, Button_X, Button_S;
	double roll_rad, pitch_rad;
	int scaledValue;
	int mode, last_b;
	char print;
	char OutString[81];
	
	do
	{
		
		if(Button_T == 1 && last_b != 1)
		{
			if(mode == PITCH)
			{
				mode = ROLL;
			}
			else if (mode == ROLL)
			{
				mode = PITCH;
			}
		}
		
		roll_rad = roll(-1 * g_x);
		pitch_rad = pitch(g_y);
		
		if(mode == ROLL)
		{
			scaledValue = scaleRadsForScreen(roll_rad);
		}
		else if (mode == PITCH)
		{
			scaledValue = scaleRadsForScreen(pitch_rad);
		}
		
		if(mode == ROLL)
		{
			print = "r";
		}
		else if (mode == PITCH)
		{
			print = "l";
		}
		
		print_chars(scaledValue, print);
		
		fflush(stdout);
		last_b = Button_T;
		
	} while(read_line(&g_x, &g_y, &g_z, &time, &Button_T, &Button_C, &Button_X, &Button_S));
		
}//End Main

int read_line(double* g_x, double* g_y, double* g_z, int* time, int* Button_T, int* Button_C, int* Button_X, int* Button_S)
{
	scanf("%d, %lf, %lf, %lf, %d, %d, %d, %d", time, g_x, g_y, g_z, Button_T, Button_C, Button_X, Button_S);
	int quit;
	if( *Button_S != 1)
	{
		quit = TRUE;
	}
	else
	{
		quit = FALSE;
	}
	return quit;
}

double roll(double x_mag)
{
	if(x_mag > 1)
	{
		return asin(1);
	}
	else if(x_mag < -1)
	{
		return asin(-1);
	}
	else
	{
		return asin(x_mag);
	}
	return -1;
}

double pitch(double y_mag)
{
	if(y_mag > 1)
	{
		return asin(1);
	}
	else if (y_mag < 1)
	{
		return asin(-1);
	}
	else
	{
		return asin(y_mag);
	}
	return -1;
}

int scaleRadsForScreen(double rad)
{
	int output;
	if(rad <= - PI/2)
	{
		output = -39;
	}
	else if (rad >= PI/2)
	{
		output = 39;
	}
	else
	{
		output = (rad - (-PI/2)) * (39 - -39) / ((PI/2) - (-PI/2)) + -39;
	}
	return output;
}

void print_chars(int num, char use)
{
	int i, diff , p_num;
	if(num > 0)
	{
		for(i=0; i < 39; i++)
		{
			printf(" ");
		}
		for(i = 0; i < num; i++)
		{
			printf("%c", 'r');
		}
	}
	else if (num < 0)
	{
		p_num = fabs(num);
		diff = 39 - p_num;
		for(i =0; i < diff;  i++)
		{
			printf(" ");
		}
		for(i = 0; i < p_num; i++)
		{
			printf("%c", 'l');
		}
	}
	else if (num == 0)
	{
		printf("%d", 0);
	}
	printf("\n");
}

void graph_line(int number)
{
	
}

double mag(double x, double y, double z)
{
	return sqrt(pow(x,2) + pow(y,2) + pow(z, 2));
}
