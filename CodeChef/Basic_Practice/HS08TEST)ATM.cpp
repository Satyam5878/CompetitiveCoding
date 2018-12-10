// REFERENCE CODE for Populating:
// https://www.codechef.com/viewsolution/19864707 

#include<iostream>
#include<ctime>

// Finding min and max
#define max(a,b) ((a)>(b))?(a):(b)
#define min(a,b) ((a)<(b))?(a):(b)

// program Run time
#define start_time_routine  clock_t start_time = clock();
#define end_time_routine clock_t end_time = clock(); \
        double time_elapsed = double(end_time-start_time)/CLOCKS_PER_SEC;\
        printf("\n\n%.3f\n",time_elapsed);\

// Register defined loop variable
#define ri register int
#define rlli register long long int 


using namespace std;

int main() {
	//start_time_routine;

	int X;
	double  Y;
	cin >> X >> Y;
	if (X % 5 == 0 && X + 0.5 <= Y) {
		printf("%.2f",( Y-X-0.5));
	}
	else {
		printf("%.2f", Y);
	}

	//end_time_routine
	return 0;

}