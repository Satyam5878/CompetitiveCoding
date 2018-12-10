#include<iostream>

using namespace std;
#define MAX_SIZE 100+5
int d[MAX_SIZE];

int main() {
	int T,n,di;
	cin >> T; // reading no. of test case
	for (int tc = 1;tc <= T;++tc) {
		cin >> n; // no. of friends
		for (int i = 0;i < n;++i) {
			cin >> di; // ith friend's party day
			d[di] = tc; // setting to tc no., indicate if any
						// person want party that day. 
		}
		
		int count = 0;
		for (int i = 1;i <= 100;++i) {
			if (d[i] == tc) {
				count++;
			}
		}
		cout << count << '\n';
	}
	return 0;
}