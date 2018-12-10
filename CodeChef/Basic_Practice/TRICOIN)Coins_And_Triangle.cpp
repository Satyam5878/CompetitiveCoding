#include<iostream>

using namespace std;
inline long long int sum(long long int n) {
	return n*(n + 1) >> 1;
}
int main() {
	long long int T, N, low, high, mid, total, total2;
	cin >> T;
	for (int tc = 0; tc < T; ++tc) {
		cin >> N;
		low = 0;
		high = 100000;
		while (low <= high) {
			mid = high - ((high - low) >> 2);
			total = sum(mid);
			if (total == N) {
				cout << mid << '\n';
				break;
			}
			else if (total>N) {
				total2 = sum(mid - 1);
				if (total2 <= N) {
					cout << mid - 1 << '\n';
					break;
				}
				else {
					high = mid - 1;
				}
			}
			else {
				total2 = sum(mid + 1);
				if (N < total2) {
					cout << mid << '\n';
					break;
				}
				else if (N == total2) {
					cout << mid + 1 << '\n';
					break;
				}
				else {
					low = mid + 1;
				}
			}
		}
	}
	return 0;
}