
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


// FAST_IO
#define FAST_IO ios_base::sync_with_stdio(false);\
        cin.tie(0);\   

// function for taking no as input
// for positive no.s only
inline long long int fastRead_int() {
	long long int ans = 0;
	char c = getchar();
	while (c<'0' || c>'9') c = getchar();
	while (c >= '0' && c <= '9') {
		//ans = ans*10 + (c-'0');
		ans = (ans << 1) + (ans << 3) + (c - '0');
		c = getchar();
	}
	return ans;
}

using namespace std;
inline int countFour(int N) {
	ri count = 0;
	while (N) {
		if (N % 10 == 4) {
			count++;
		}
		N = N / 10;
	}
	return count;

}

int main() {
	long long int T,N;
	int ans;
	/*
	T = fastRead_int();
	for (ri tc = 0;tc < T;++tc) {
		N = fastRead_int();
		ans = countFour(N);
		cout << ans << "\n";
	}*/
	T = fastRead_int();
	char c;
	long long int count = 0;
	for (ri tc = 0;tc < T;) {
		c = getchar();
		if (c == '\n') {
			tc++;
			cout << count << "\n";
			count = 0;
		}
		else if(c =='4'){
			count++;
		}
		
	}
	
	return 0;

}