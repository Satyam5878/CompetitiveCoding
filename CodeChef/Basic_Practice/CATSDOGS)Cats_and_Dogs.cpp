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
        double time_elapsed = double(end_time-start_time)/CLOCKS_PER_SEC;\
        printf("%.3f",time_elapsed);\

// Register defined loop variable
#define ri register int
#define rlli register long long int 
#define lli long long int

// FAST_IO Stream and stdio sync
#define FAST_IO ios_base::sync_with_stdio(false);\
        cin.tie(0);  

// function for taking no as input
// for positive no.s only
inline lli  fastRead_int() {
	lli  ans = 0;
	char c = getchar();
	int neg = 1;
	if (c == '-') {
		neg = -1;
		c = getchar();
	}
	while (c<'0' || c>'9') c = getchar();
	while (c >= '0' && c <= '9') {
		//ans = ans*10 + (c-'0');
		ans = (ans << 1) + (ans << 3) + (c - '0');
		c = getchar();
	}
	return ans*neg;
}

// FAST Output Code:
#define MAX_BUFFER_SIZE 600000
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
	// start writing string to buffer
	for (ri i = 0;str[i] != '\0';++i) {
		// if buffer is full, i.e. we are at the last index
		// then write '\0' to the buffer and flush it
		// and decrease the i to again write the charactrer at ith location
		if (currBufferIdx >= (MAX_BUFFER_SIZE - 1)) {
			buffer[currBufferIdx] = '\0';
			flushBuffer();
			--i;
		}
		else {
			buffer[currBufferIdx++] = str[i];
		}
	}
	// write the '\0' at the end of string 
	// so if we call flushBuffer, it does not give any error.
	// here we are no increasing the currBufferIdx, 
	// next time we will start writing from this location only.
	buffer[currBufferIdx] = '\0';

}
inline void fastWriteToBuffer_int(int num) {
	int idx = 0;
	bool isNeg = false;
	// if num is zero:
	if (num == 0) {
		buffer[currBufferIdx++] = '0';
		return;
	}
	// if num is negative:	
	if (num<0) {
		num = -num;
		isNeg = true;
	}
	while (num) {
		numStr[idx++] = (num % 10 + '0');
		num /= 10;
	}
	// if neg, add the -ve sign
	if (isNeg) {
		numStr[idx++] = '-';
	}
	for (ri i = idx - 1;i >= 0;--i) {
		if (currBufferIdx >= (MAX_BUFFER_SIZE - 1)) {
			buffer[currBufferIdx] = '\0';
			flushBuffer();
			++i;
		}
		else {
			buffer[currBufferIdx++] = numStr[i];
		}
	}
	buffer[currBufferIdx] = '\0';
}

//-----------------------_/\_Main Program Start Here_/\_------------------

#include<iostream>
using namespace std;
#define lli long long int
int main() {
	lli T,C,D,L,Lo,Lh;
	//cin >> T;
	T = fastRead_int();
	for (int tc = 0;tc < T;++tc) {
		//cin >> C >> D >> L;
		C = fastRead_int();
		D = fastRead_int();
		L = fastRead_int();

		Lh = (C + D) * 4;
		if (C <= 2 * D) {
			Lo = 4 * D;
		}
		else {
			Lo = 4 * (D + (C - 2 * D));
		}
		if (L % 4 == 0 && L <= Lh && L >= Lo) {
			//cout << "yes\n";
			fastWriteToBuffer_str("yes\n");
		}
		else {
			//cout << "no\n";
			fastWriteToBuffer_str("no\n");
		}
	}
	flushBuffer();
	return 0;
}