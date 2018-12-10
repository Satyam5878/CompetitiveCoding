#include<iostream>
#include<ctime>

// For Runtime Optmization
#pragma GCC optimize ("Ofast")

// Finding min and max
#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))
#define abs(a) ((a>0)?a:-a)
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
#define MAX_SIZE 1000+2
int arr[MAX_SIZE][MAX_SIZE];
char res[MAX_SIZE][MAX_SIZE];
int main() {
	//start_time_routine;
	int T,N,M;
	T = fastRead_int();
	for (ri tc = 0;tc < T;++tc) {
		N = fastRead_int();
		M = fastRead_int();
		for (ri i = 0;i < N;++i) {
			for (ri j = 0;j < M;++j) {
				//arr[i][j] = fastRead_int();
				cin >> arr[i][j];
			}
		}
		bool flag;;
		int dis;
		for (ri i = 0;i < N;++i) {
			for (ri j = 0;j < M;++j) {
				if (arr[i][j] == -1) {
					res[i][j] = 'B';
					continue;
				}
				else {
					flag = false;
					for (ri k = 0;k < N;++k) {
						for (ri l = 0;j < M;++l) {
							if (i == k && j == l) {
								continue;
							}
							dis = abs(k - i) + abs(l - j);
							if (arr[k][l] > dis) {
								flag = true;
								break;
							}
						}
						if (flag == true) {
							break;
						}
					}
					if (flag) {
						res[i][j] = 'Y';
					}
					else {
						res[i][j] = 'N';
					}

				}			
			}
		}

		for (ri i = 0;i < N;++i) {
			for (ri j = 0;j < M;++j) {
				cout << res[i][j] << " ";
			}
			cout << '\n';
		}

	}


	//end_time_routine;
	return 0;
}