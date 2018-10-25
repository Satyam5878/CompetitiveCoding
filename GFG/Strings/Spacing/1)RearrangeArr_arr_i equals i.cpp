#include<iostream>

using namespace std;

#define MAX_SIZE 100
int tmp[MAX_SIZE];

/*
	Using temporary array:
	O(3n)
*/
void rearrange(int arr[], int n) {
	for (int i = 0;i < n;++i) {
		tmp[i] = -1;
	}
	for (int i = 0;i < n;++i) {
		if (arr[i] != -1) {
			tmp[arr[i]] = arr[i];
		}
	}

	for (int i = 0;i < n;++i) {
		arr[i] = tmp[i];
	}
}
void printArray(int arr[], int n) {
	for (int i = 0;i < n;++i) {
		cout << arr[i] << " ";
	}
}

int main() {
	int arr[] = { -1, -1, 6, 1, 9, 3, 2, -1, 4, -1 };
	int a[] = { 1,2,3 };
	int len = 10;
	rearrange(arr, len);
	printArray(arr, len);

	return 0;

}