
//-------------------------------------------------------------------------------------
#include<iostream>
#include<stdio.h>
#include<ctime>

// Finding min and max
#define max(a,b) ((a)>(b))?(a):(b)
#define min(a,b) ((a)<(b))?(a):(b)

// program Run time
#define start_time_routine  clock_t start_time = clock();
#define end_time_routine clock_t end_time = clock(); \
        double time_elapsed = double(end_time-start_time)/CLOCKS_PER_SEC;\
        printf("%.3f",time_elapsed);\

// Register defined loop variable
#define ri register int
#define rlli register long long int 

// function for taking no as input
// for positive no.s only
inline int fastRead_int() {
	int ans = 0;
	char c = getchar();
	while (c<'0' || c>'9') c = getchar();
	while (c >= '0' && c <= '9') {
		//ans = ans*10 + (c-'0');
		ans = (ans << 1) + (ans << 3) + (c - '0');
		c = getchar();
	}
	return ans;
}

// for -ve no
inline int fastRead_int_() {

}
inline void fastRead_string(char *str) {

}
//-----------------------------------------------------------------------------------------------------
// Fast Output:




//-------------------------------------------------Main Program----------------------------------------
// Program Variable



using namespace std;

int main() {
	int N,p1CumS=0,p2CumS=0,p1,p2,W,L,maxL = -10000;
	N = fastRead_int();
	for (ri i = 0;i < N;++i) {
		p1 = fastRead_int();
		p2 = fastRead_int();
		p1CumS += p1;
		p2CumS += p2;
		L = ((p1CumS > p2CumS) ? (p1CumS - p2CumS) : (p2CumS - p1CumS));
		if (L > maxL) {
			W = ((p1CumS > p2CumS) ? 1 : 2);
			maxL = L;
		}
	}
	//cout << W << " " << maxL;
	printf("%d %d", W,maxL);
	return 0;

}