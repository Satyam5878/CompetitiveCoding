

#include<iostream>
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

#define FAST_IO ios_base::sync_with_stdio(false);\
				cin.tie(0);\

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

// Fast Output:

// Program Variable



using namespace std;

inline int sumOfDigits(int N) {
	
	int ans = 0;
	while (N) {
		ans += N % 10;
		N = N/10;
	}
	return ans;
}

int main() {
	FAST_IO;
	int T,N,ans;
	T = fastRead_int();
	for (ri tc = 0;tc < T;++tc) {
		N = fastRead_int();
		ans = sumOfDigits(N);
		cout << ans << "\n";
	}
	return 0;

}