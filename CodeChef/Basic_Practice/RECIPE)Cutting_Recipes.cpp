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
#define MAX_BUFFER_SIZE_LINE 300
char bulkReadBuffer[MAX_BUFFER_SIZE_LINE];
int arr[50 + 2];

inline int gcd(int a, int b) {
	return (b == 0) ? a : (gcd(b, a%b));
}
int main() {
	//start_time_routine;
	
	int T,N,num,g;
	T = fastRead_int();
	for (ri tc = 0;tc < T;++tc) {
		N = fastRead_int();
		fgets(bulkReadBuffer,MAX_BUFFER_SIZE_LINE,stdin);
		
		num = 0;g = 1;
		for (ri i = 0,j=0;i < MAX_BUFFER_SIZE_LINE;++i,++j) {
			num = 0;
			while (bulkReadBuffer[i] >= '0' && bulkReadBuffer[i] <= '9') {
				num = (num << 1) + (num << 3) + (bulkReadBuffer[i] - '0');
				++i;
			}
			arr[j] = num;
			if (j == 0) {
				g = arr[j];
			}
			g = gcd(g, arr[j]);
			if (g == 0) {
				break;
			}
			if (bulkReadBuffer[i] == '\n') {
				break;
			}

		}
		if (g == 0) {
			g = 1;
		}
		for (ri i = 0;i < N;++i) {
			fastWriteToBuffer_int(arr[i] / g);
			fastWriteToBuffer_str(" ");
		}
		fastWriteToBuffer_str("\n");
	}

	flushBuffer();
	//end_time_routine;
	return 0;

	
	/*
	int T,N,g;
	cin >> T;
	for (ri tc = 0;tc < T;++tc) {
		cin >> N;
		for (ri i = 0;i < N;++i) {
			cin >> arr[i];
			if (i == 0) {
				g = arr[i];
			}
			g = gcd(g, arr[i]);
		}
		if (g == 0) {
			g = 1;
		}
		for (ri i = 0;i < N;++i) {
			cout << arr[i]/g << " ";
		}


		cout << "\n";

	}
	*/
}