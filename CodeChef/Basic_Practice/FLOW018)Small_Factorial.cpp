
#include<iostream>
#include<ctime>

// Finding min and max
#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))

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
	for (ri i = 0;str[i] != '\0';++i) {
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
		buffer[currBufferIdx++] =  '0';
		return;
	}
	while (num) {
		numStr[idx++] = (num % 10 + '0');
		num /= 10;
	}
	for (ri i = idx - 1;i >= 0;--i) {
		if (currBufferIdx >= MAX_BUFFER_SIZE) {
			flushBuffer();
		}
		else {
			buffer[currBufferIdx++] = numStr[i];
		}
	}
}

//---------------------------_/\_Main Program Start Here_/\_---------------------

using namespace std;
int arr[150];
int idx;
inline void multiply(int num) {
	int carry = 0,tmp;
	for (ri i = 0;i <= idx;++i) {
		tmp = (arr[i] * num + carry);
		arr[i] = tmp%10;
		carry = tmp / 10;
	}
	while (carry) {
		arr[++idx] = carry % 10;
		carry /= 10;
	}
}
inline void printFact() {
	for (ri i = idx;i >= 0;--i) {
		fastWriteToBuffer_int(arr[i]);
	}
	fastWriteToBuffer_str("\n");
}
int main() {
	int T,N;
	T = fastRead_int();
	for (ri tc = 0;tc < T;++tc) {
		N = fastRead_int();
		idx = 0;

		arr[0] = 1;
		for (ri i = N;i >= 2;--i) {
			multiply(i);
		}
		printFact();
	}

	flushBuffer();
	return 0;

}