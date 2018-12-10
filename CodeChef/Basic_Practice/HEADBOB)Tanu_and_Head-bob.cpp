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

// FAST_IO Stream and stdio sync
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
		buffer[currBufferIdx++] = '0';
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

//-----------------------_/\_Main Program Start Here_/\_------------------
using namespace std;
#include<string>
int main() {
	start_time_routine;
	/*
	int T,N;
	string s;
	int n, y, i;
	T = fastRead_int();
	for (ri tc = 0;tc < T;++tc) {
		N = fastRead_int();
		cin >> s;
		n = y = i = 0;
		for (auto c : s) {
			if (c == 'N') {
				n++;
			}
			else if (c == 'Y') {
				y++;
			}
			else {
				i++;
			}
		}
		if (y == 0 && i == 0) {
			fastWriteToBuffer_str("NOT SURE\n");
		}
		else if(y >0) {
			fastWriteToBuffer_str("NOT INDIAN\n");
		}
		else {
			fastWriteToBuffer_str("INDIAN\n");
		}
	}
	
	*/
	int T, N;
	string s;
	int n, y, i;
	T = fastRead_int();
	bool flag;
	for (ri tc = 0;tc < T;++tc) {
		N = fastRead_int();
		cin >> s;
		n = y = i = 0;
		flag = false;
		for (auto c : s) {
			if (c == 'I') {
				fastWriteToBuffer_str("INDIAN\n");
				flag = true;
				break;
			}
			else if (c == 'Y') {
				fastWriteToBuffer_str("NOT INDIAN\n");
				flag = true;
				break;
			}
			
		}
		if (!flag) {
			fastWriteToBuffer_str("NOT SURE\n");
		}
		
	}

	flushBuffer();
	//end_time_routine;


	return 0;
}