#include<iostream>

using namespace std;
#define MAX_SIZE 45
int X[MAX_SIZE];
int Y[MAX_SIZE];
bool visited[MAX_SIZE];



int main() {
	int T, N, x, y;
	int res;
	cin >> T;
	for (int tc = 0; tc < T; ++tc) {
		cin >> N;
		res = 0;
		for (int i = 0; i < N; ++i) {
			cin >> x >> y;
		}

		for (int i = 1; i <= N; ++i) {
			res = res^i;
		}
		cout << res << '\n';
	}

	return 0;
}