

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


using namespace std;
#define MAX_SIZE 300
int arr[MAX_SIZE];
int idx;

void init() {
	for (ri i = 0;i < MAX_SIZE;++i) {
		arr[i] = 0;
	}
	idx = 0;
}

void multiply(int num) {
	int carry = 0, tmp;
	for (ri i = 0;i < idx;++i) {
		tmp = arr[i] * num + carry;
		arr[i] = tmp % 10;
		carry = tmp / 10;
	}
	while (carry) {
		arr[idx++] = carry % 10;
		carry /= 10;
	}
}
void findFactorial(int N) {
	arr[0] = 1;
	idx = 1;
	for (ri i = N;i > 1;--i) {
		multiply(i);
	}
}

void printFactorial() {
	for (ri i = idx - 1;i >= 0;--i) {
		cout << arr[i];
	}
}

int main() {
	int T,N;
	cin >> T;
	for (ri tc = 0;tc < T;++tc) {
		cin >> N;
		init();   // Resetting the array
		findFactorial(N);   // finding the factorial
		printFactorial();
		cout << endl;
	}
	return 0;

}