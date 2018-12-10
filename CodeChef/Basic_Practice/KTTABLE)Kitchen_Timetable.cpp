#include<iostream>
#include<ctime>

// For Runtime Optmization
#pragma GCC optimize ("Ofast")

// Finding min and max
#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))

// program Run time
#define start_time_routine  clock_t start_time = clock();
#define end_time_routine clock_t end_time = clock(); \
	double time_elapsed = double(end_time - start_time) / CLOCKS_PER_SEC; \
	printf("%.3f", time_elapsed); \

// Register defined loop variable
#define ri register int
#define rlli register long long int 

// FAST_IO Stream and stdio sync
#define FAST_IO ios_base::sync_with_stdio(false);\
	cin.tie(0);

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

// FAST Output Code:
#define MAX_BUFFER_SIZE 65536
#define MAX_NUM_SIZE 20
char buffer[MAX_BUFFER_SIZE];
int currBufferIdx;
char numStr[MAX_NUM_SIZE];
inline void initBuffer() {
	currBufferIdx = 0;
}
inline void flushBuffer() {
	fwrite(buffer, sizeof(char), currBufferIdx, stdout);
	currBufferIdx = 0;
}
inline void fastWriteToBuffer_str(const char *str) {
	for (ri i = 0; str[i] != '\0'; ++i) {
		if (currBufferIdx >= MAX_BUFFER_SIZE) {
			flushBuffer();
		}
		else {
			buffer[currBufferIdx++] = str[i];
		}
	}
}
inline void fastWriteToBuffer_int(int num) {
	int idx = 0;
	if (num == 0) {
		buffer[currBufferIdx++] = '0';
		return;
	}
	while (num) {
		numStr[idx++] = (num % 10 + '0');
		num /= 10;
	}
	for (ri i = idx - 1; i >= 0; --i) {
		if (currBufferIdx >= MAX_BUFFER_SIZE) {
			flushBuffer();
		}
		else {
			buffer[currBufferIdx++] = numStr[i];
		}
	}
}

//-----------------------_/\_Main Program Start Here_/\_------------------
#include<iostream>

using namespace std;
#define MAX_SIZE 10000 + 7
long long int A[MAX_SIZE];
long long int B[MAX_SIZE];

int main() {
	long long int T, N, count;
	//cin >> T;
	T = fastRead_int();
	for (int tc = 0; tc < T; ++tc) {
		//cin >> N;
		N = fastRead_int();
		//reading A's element :
		for (int i = 1; i <= N; ++i) {
			//cin >> A[i];
			A[i] = fastRead_int();
		}
		// reading B's element:
		for (int i = 1; i <= N; ++i) {
			//cin >> B[i];
			B[i] = fastRead_int();
		}
		// algo:
		count = 0;
		for (int i = 1; i <= N; ++i) {
			if (B[i] <= (A[i] - A[i - 1])) {
				count++;
			}
		}
		fastWriteToBuffer_int(count);
		fastWriteToBuffer_str("\n");
		//cout << count << "\n";
	}
	flushBuffer();
	return 0;
}