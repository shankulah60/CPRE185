// 185 lab6.c
//
// This is the outline for your program
// Please implement the functions given by the prototypes below and
// complete the main function to make the program complete.
// You must implement the functions which are prototyped below exactly
// as they are requested.

#include <stdio.h>
#include <math.h>
#define PI 3.141592653589
#define ROLL 0
#define PITCH 1
#define TRUE 1
#define FALSE 0

// Use
// ./ds4rd.exe -d 054c:05c4 -D DS4_BT -t -g -b | ./lab6.exe
// to run

//NO GLOBAL VARIABLES ALLOWED


//PRE: Arguments must point to double variables or int variables as appropriate
//This function scans a line of DS4 data, and returns
// True when the square button is pressed
// False Otherwise
//This function is the ONLY place scanf is allowed to be used
//POST: it modifies its arguments to return values read from the input line.
int read_line(double* g_x, double* g_y, double* g_z, int* time, int* Button_T, int* Button_C, int* Button_X, int* Button_S);

// PRE: -1.0 <= x_mag <= 1.0
// This function computes the roll of the DS4 in radians
// if x_mag outside of -1 to 1, treat it as if it were -1 or 1
// POST: -PI/2 <= return value <= PI/2
double roll(double x_mag);

// PRE: -1.0 <= y_mag <= 1.0
// This function computes the pitch of the DS4 in radians
// if y_mag outside of -1 to 1, treat it as if it were -1 or 1
// POST: -PI/2 <= return value <= PI/2
double pitch(double y_mag);


// PRE: -PI/2 <= rad <= PI/2
// This function scales the roll value to fit on the screen
// POST: -39 <= return value <= 39
int scaleRadsForScreen(double rad);

// PRE: num >= 0
// This function prints the character use to the screen num times
// This function is the ONLY place printf is allowed to be used
// POST: nothing is returned, but use has been printed num times
void print_chars(int num, char use);

//PRE: -39 <= number <=39
// Uses print_chars to graph a number from -39 to 39 on the screen.
// You may assume that the screen is 80 characters wide.
void graph_line(int number);

int main()
{
int time; // tiempo ese
double a_x, a_y, a_z; // magnitude values of x, y, and z
double g_x, g_y, g_z; // more values of x, y, and z (not needed lol)
 	int Button_T, Button_C, Button_X, Button_S; // variables to hold the button statuses
double roll_rad, pitch_rad; // value of the roll measured in radians
int scaled_value; // value of the roll adjusted to fit screen display
int mode, last_b;
char print;
//insert any beginning needed code here
char outputString[81]; // 81 since string literals in C are stored with a terminating 0 byte.

do
{
// Get line of input
// scanf("%d, %lf, %lf, %lf, %lf, %lf, %lf, %d, %d, %d, %d", &t, &ax, &ay, &az, &gx, &gy, &gz, &b_Triangle, &b_Circle, &b_X, &b_Square);
// calculate roll and pitch. Use the buttons to set the condition for roll and pitch || Button order is: triangle, circle, x, square
// switch between roll and pitch(up vs. down button)
// on run, graph roll, use Tri to go to roll, and X to go to pitch.

if(Button_T == 1 && last_b != 1) {
if(mode == PITCH) {
mode = ROLL;
// printf("ROLL\n");
} else if(mode == ROLL) {
mode = PITCH;
// printf("PITCH\n");
}
}

roll_rad = roll(-1 * g_x);
pitch_rad = pitch(g_y);

// Scale your output value
// asin is defined on -pi/2 to pi/2
if(mode == ROLL) {
scaled_value = scaleRadsForScreen(roll_rad);
} else if(mode == PITCH) {
scaled_value = scaleRadsForScreen(pitch_rad);
}

if(mode == ROLL) {
print = 'r';
} else if(mode == PITCH) {
print = 'l';
}

print_chars(scaled_value, print);

fflush(stdout);
last_b = Button_T;
} while (read_line(&g_x, &g_y, &g_z, &time, &Button_T, &Button_C, &Button_X, &Button_S)); // Modify to stop when the square button is pressed
// (g_x, g_y, g_z, time, Button_T, Button_C, Button_X, Button_S)

return 0;
}


//PRE: Arguments must point to double variables or int variables as appropriate
//This function scans a line of DS4 data, and returns
// True when the square button is pressed
// False Otherwise
//This function is the ONLY place scanf is allowed to be used
//POST: it modifies its arguments to return values read from the input line.
int read_line(double* g_x, double* g_y, double* g_z, int* time, int* Button_T, int* Button_C, int* Button_X, int* Button_S){
scanf("%d, %lf, %lf, %lf, %d, %d, %d, %d", time, g_x, g_y, g_z, Button_T, Button_C, Button_X, Button_S);
// printf("%d\n", Button_S);
// printf("%lf\n", g_x);
int quit;
if(*Button_S != 1) {
quit = TRUE;
} else {
quit = FALSE;
}
return (quit);
}

// PRE: -1.0 <= x_mag <= 1.0
// This function computes the roll of the DS4 in radians
// if x_mag outside of -1 to 1, treat it as if it were -1 or 1
// POST: -PI/2 <= return value <= PI/2
// DONE!
double roll(double x_mag){
if (x_mag > 1){
return asin(1);
} else if (x_mag < -1){
return asin(-1);
} else {
return asin(x_mag);
}
return 0;
}

// PRE: -1.0 <= y_mag <= 1.0
// This function computes the pitch of the DS4 in radians
// if y_mag outside of -1 to 1, treat it as if it were -1 or 1
// POST: -PI/2 <= return value <= PI/2
// DONE!
double pitch(double y_mag){
if (y_mag > 1){
return asin(1);
} else if (y_mag < -1){
return asin(-1);
} else {
return asin(y_mag);
}
return 0;
}

// PRE: -PI/2 <= rad <= PI/2
// This function scales the roll value to fit on the screen
// POST: -39 <= return value <= 39
// DONE!
int scaleRadsForScreen(double rad){
int output;
if(rad <= -PI/2) {
output = -39;
} else if(rad >= PI/2) {
output = 39;
} else {
// opted to use map function here
output = (rad - (-PI/2)) * (39 - -39) / ((PI/2) - (-PI/2)) + -39;
}
return output;
}

// PRE: num >= 0
// This function prints the character use to the screen num times
// This function is the ONLY place printf is allowed to be used
// POST: nothing is returned, but use has been printed num times
void print_chars(int num, char use){
int i, diff, p_num;
if(num > 0) {
for(i=0;i<39;i++) {
printf(" ");
}
for(i=0;i<num;i++) {
printf("%c", 'r');
}
} else if(num < 0) {
p_num = fabs(num);
diff = 39-p_num;
for(i=0;i<diff;i++) {
printf(" ");
}
for(i=0;i<p_num;i++) {
printf("%c", 'l');
}
} else if(num == 0) {
for(i=0;i<39;i++) {
printf(" ");
}
printf("0");
}
printf("\n");
}

//PRE: -39 <= number <=39
// Uses print_chars to graph a number from -39 to 39 on the screen.
// You may assume that the screen is 80 characters wide.
void graph_line(int number){

}

double mag(double x,double y,double z) {
return sqrt(pow(x,2) + pow(y,2) + pow(z,2));
}