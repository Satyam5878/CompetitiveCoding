
#include<iostream>
#include<ctime>
#include<cmath>
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
        cin.tie(0);  

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

using namespace std;
inline int findNoOfMenu(int N) {
	int tmp;
	int times = 0;
	for (ri i = 11;i >= 0 && N!= 0;--i) {
		tmp = (int)pow(2, i);
		times += N / tmp;
		N = N%tmp;
	}
	return times;
}
int main() {
	int T,N,ans;
	FAST_IO;
	T = fastRead_int();
	for (ri tc = 0;tc < T;++tc) {
		N = fastRead_int();
		ans = findNoOfMenu(N);
		cout << ans << "\n";
	}
	return 0;

}