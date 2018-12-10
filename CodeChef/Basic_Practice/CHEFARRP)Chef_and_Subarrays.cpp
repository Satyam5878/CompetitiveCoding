#include<iostream>

using namespace std;
#define MAX_SIZE 64
long long int arr[MAX_SIZE];
long long int sumArr[MAX_SIZE];
long long int prodArr[MAX_SIZE];



int main() {
	long long int T, N, sum, prod, count, tmpSum, tmpProd;
	cin >> T;
	for (int tc = 0; tc < T; ++tc) {
		// reading no of elemnts in arr;
		cin >> N;
		// initialising sum and product;
		sum = 0;
		prod = 1;
		for (int i = 0; i < N; ++i) {
			// reading arr element
			cin >> arr[i];
			// calculating cumulative sum and product
			sum += arr[i];
			prod *= arr[i];
			// storing the cumulative sum and product
			sumArr[i] = sum;
			prodArr[i] = prod;
		}


		// algo:
		count = 0;
		for (int i = 0; i < N; ++i) {
			for (int j = i; j < N; ++j) {
				if (i == 0) {
					tmpSum = sumArr[j];
					tmpProd = prodArr[j];
				}
				else {
					tmpSum = sumArr[j] - sumArr[i - 1];
					tmpProd = prodArr[j] / prodArr[i - 1];
				}

				if (tmpSum == tmpProd) {
					count++;
				}
			}
		}
		cout << count << '\n';



	}

	return 0;
}