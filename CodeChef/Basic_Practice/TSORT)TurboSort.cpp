
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


// Program Variable
using namespace std;
#define MAX_SIZE 1000000+7
int arr[MAX_SIZE];
int mergeArr[MAX_SIZE];

inline int getN() {
	int ans = 0;
	char c = getchar();
	while (c<'0' || c>'9') c = getchar();
	while (c >= '0' && c <= '9') {
		ans = ans * 10 + (c - '0');
		c = getchar();
	}
	return ans;
}
void printArray(int N) {
	for (ri i = 0;i < N;++i) {
		cout << arr[i] << endl;
	}
}
void mergeSort(int low, int high) {
	if (low < high) {
		int mid = (low + high) / 2;
		mergeSort(low, mid);
		mergeSort(mid + 1, high);

		int k = low, p = low, q = mid + 1;
		for (ri i =low;i <= high;++i) {
			if (p > mid) {
				mergeArr[k++] = arr[q++];
			}
			else if (q > high) {
				mergeArr[k++] = arr[p++];
			}
			else if (arr[p] < arr[q]) {
				mergeArr[k++] = arr[p++];
			}
			else {
				mergeArr[k++] = arr[q++];
			}
		}
		for (ri i = low;i <= high;++i) {
			arr[i] = mergeArr[i];
		}
	}
}


int main() {
	int T,N;
	N = getN();
	for (ri i = 0;i < N;++i) {
		arr[i] = getN();
	}
	mergeSort(0, N - 1);
	printArray(N);

	return 0;

}