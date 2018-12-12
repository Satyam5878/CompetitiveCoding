#include<iostream>
using namespace std;
#define MAX_SIZE 26
bool hashT[MAX_SIZE];
char words[MAX_SIZE];

int main() {
	cin >> words; // reading the letters he can read
	for (int i = 0;words[i] != '\0';++i) {
		hashT[words[i] - 'a'] = true; // hashing the letters
	}
	int N;
	cin >> N; // no. of words
	bool flag;
	for (int i = 0;i < N;++i) {
		cin >> words; // reading the words
		flag = true;
		for (int i = 0;words[i] != '\0';++i) {
			if (hashT[words[i] - 'a'] != true) {
				flag = false;
				break;
			}
		}
		if (flag) {
			cout << "Yes\n";
		}
		else {
			cout << "No\n";
		}
	}
	return 0;
}