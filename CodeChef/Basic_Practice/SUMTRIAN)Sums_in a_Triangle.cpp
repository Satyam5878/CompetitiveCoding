#include<iostream>
#include<ctime>
#pragma GCC ("-Ofast")
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
	while (num) {
		numStr[idx++] = (num % 10+'0');
		num /= 10;
	}
	//numStr[idx] = '\0';
	
	//fastWriteToBuffer_str(numStr);
	for (ri i = idx-1;i>=0;--i) {
		if (currBufferIdx >= MAX_BUFFER_SIZE) {
			flushBuffer();
		}
		else {
			buffer[currBufferIdx++] = numStr[i];
		}
	}
}



//---------------------------_/\_Main Program Start Here_/\_---------------------
                               
//							             ___
//							            (   )
//							          @( 0 0 )@
//							        //(   *   )\\
//			                       // (   -   ) \\
//                                //  (   _	  )	 \\
//                                ^  (   /-\   )  ^
//                                  (___/ - \___)


using namespace std;
#define MAX_ROW_SIZE 100+2
int arr[MAX_ROW_SIZE][MAX_ROW_SIZE];
int dp[MAX_ROW_SIZE];

inline void readAll(int N) {
	for (ri i = 0;i < N;++i) {
		for (ri j = 0;j <= i;++j) {
			arr[i][j] = fastRead_int();
		}
	}
	for (ri i = 0;i < N;++i) {
		dp[i] = arr[N - 1][i];
	}
}
inline void largestSumPath(int N) {
	for (ri i = N - 2;i >= 0;--i) {
		for (ri j = 0;j <= i;j++) {
			
			dp[j] = (arr[i][j] + max(dp[j], dp[j + 1]));
		}
	}

}
inline int largestSumPath_(int N) {
	arr[0][0] = fastRead_int();
	for (ri i =1;i < N;++i) {
		arr[i][0] = fastRead_int();
		arr[i][0] += arr[i - 1][0];
		for (ri j = 1;j < i;j++) {
			arr[i][j] = fastRead_int();
			arr[i][j]= (arr[i][j] + max(arr[i-1][j-1], arr[i-1][j]));
		}
		arr[i][i] = fastRead_int();
		arr[i][i] += arr[i - 1][i - 1];
	}
	int maxPath = 0;
	for (ri i = 0;i < N;++i) {
		maxPath = max(maxPath, arr[N - 1][i]);
	}
	return maxPath;
}
int main() {
	int T,N;
	T = fastRead_int();
	FAST_IO;
	for (ri tc = 0;tc < T;++tc) {
		N = fastRead_int();
		//readAll(N);
		//largestSumPath(N);
		//cout << largestSumPath_(N)<<'\n';
		fastWriteToBuffer_int(largestSumPath_(N));

		fastWriteToBuffer_str("\n");
		//cout << dp[0]<<"\n";
		
	}
	flushBuffer();
	return 0;

}