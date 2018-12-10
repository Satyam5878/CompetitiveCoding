#include<iostream>

using namespace std;
#define MAX_SIZE 100000
long long int S[MAX_SIZE];
long long int FS[MAX_SIZE];
long long int lps[MAX_SIZE];


/* Function to calculate the lps array.*/
void LPS(int F) {
	int j = 0, i;
	for (int i = 1;i < F;) {
		/* check if elements are equal*/
		if (FS[i] == FS[j]) {
			lps[i] = j + 1; 
			i++;j++;
		}
		else {
			if (j != 0) {
				j = lps[j - 1];
			}
			else {
				lps[i] = 0;
				i++;
			}
		}
	}
}
/* Function to search for the pattern.*/
int KMPSearch(int N, int F) {
	int j = 0;
	for (int i = 0;i < N;) {
		/* check if two element have the match*/
		if (S[i] == FS[j]) {
			i++;j++; 
		}
		/* if we reach the end of favorite sequence, we ahve the found the pattern*/
		if (j == F) {
			return 1; 
		}
		/* if the there is mismatch after j match*/
		else if (i < N && S[i] != FS[j]) {
			if (j != 0) {
				j = lps[j - 1];
			}
			else {
				i++;
			}
		}
	}
	return 0;
}

void changeFlow() {
	long long int T, N, F, res;
	cin >> T;
	for (int tc = 0;tc < T;++tc) {
		cin >> N;
		for (int i = 0;i < N;++i) {
			cin >> S[i];
		}
		cin >> F;
		for (int i = 0;i < F;++i) {
			cin >> FS[i];
		}

		/*Check if FS exists in S as a subsequence*/
		int j = 0;
		for (int i = 0;i < N;++i) {
			if (S[i] == FS[j]) {
				j++;
			}
			if (j == F) {
				break;
			}
		}
		if (j == F) {
			cout << "Yes\n";
		}
		else {
			cout << "No\n";
		}

	}
}


int main() {
	changeFlow();
	return 0;

	long long int T,N,F,res;
	cin >> T; /* Reading no. of test case*/
	for (int tc = 0;tc < T;++tc) {
		cin >> N; /*Reading no. of element in sequence*/
		for (int i = 0;i < N;++i) {
			cin >> S[i];
		}
		
		/* Reading the no. of element in Favorite Sequence*/
		cin >> F;
		for (int i = 0;i < F;++i) {
			/* Reading the favorite sequence*/
			cin >> FS[i];
		}
		
		/* Calculating the lps of favorite sequence*/
		LPS(F);

		res = KMPSearch(N, F);
		if (res) {
			cout << "Yes\n";
		}
		else {
			cout << "No\n";
		}
	}
	return 0;
}


