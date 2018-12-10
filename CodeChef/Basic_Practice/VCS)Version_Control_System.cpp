#include<iostream>

using namespace std;
#define MAX_SIZE 107
int gnored[MAX_SIZE];
int track[MAX_SIZE];
int filePresent[MAX_SIZE];
int main() {
	int T, N, M, K;
	int  num;
	cin >> T;
	int count_it, count_ui_ut;
	for (int tc = 1; tc <= T; ++tc) {
		cin >> N >> M >> K;
		count_it = count_ui_ut = 0;
		// reading the ignored file no.
		for (int i = 0; i < M; ++i) {
			cin >> num;
			gnored[num] = -tc;
			filePresent[num] = tc;
		}
		// reading the tracked files no.
		for (int i = 0; i < K; ++i) {
			cin >> num;
			track[num] = -tc;
			filePresent[num] = tc;
		}

		// algo:
		for (int i = 1; i <= N; ++i) {
			if (track[i] == -tc && gnored[i] == -tc) {
				count_it++;
			}
			if (track[i] != -tc && gnored[i] != -tc) {
				count_ui_ut++;
			}
		}
		cout << count_it << " " << count_ui_ut << '\n';
	}
	return 0;
}