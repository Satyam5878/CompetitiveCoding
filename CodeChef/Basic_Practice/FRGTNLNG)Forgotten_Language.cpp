#include<iostream>

using namespace std;
#define MAX_SIZE 107
#define MAX_STR_LEN 7
#define MAX_CHILD 26
#define MAX_NO_NODE 15000+100
char word[MAX_SIZE][MAX_STR_LEN];
char pWord[MAX_STR_LEN];

struct TrieNode {
	bool isEnd;
	struct TrieNode* child[MAX_CHILD];

};
struct TrieNode * trie;
// Memory pool:
struct TrieNode mempool[MAX_NO_NODE];
struct TrieNode* mempoolAddr[MAX_NO_NODE];
int mempoolIdx;
int initOnce = 0;

struct TrieNode *getNode() {
	struct TrieNode *tmpNode = mempoolAddr[mempoolIdx++];
	tmpNode->isEnd = false;
	for (int i = 0; i < MAX_CHILD; ++i) {
		tmpNode->child[i] = nullptr;
	}
	return tmpNode;
}

void init() {
	if (initOnce == 0) {
		for (int i = 0; i < MAX_NO_NODE; ++i) {
			mempoolAddr[i] = &mempool[i];
		}
		initOnce = 1;
	}
	mempoolIdx = 0;
	trie = getNode();
}


// Trie:



void insert(char w[]) {
	struct TrieNode *ptr = trie;
	int idx;
	for (int i = 0; w[i] != '\0'; ++i) {
		idx = w[i] - 'a';
		if (ptr->child[idx] == nullptr) {
			ptr->child[idx] = getNode();
		}
		ptr = ptr->child[idx];
	}
	ptr->isEnd = true;
}
int searchWord(char w[]) {
	struct TrieNode *ptr = trie;
	int idx;
	for (int i = 0; w[i] != '\0'; ++i) {
		idx = w[i] - 'a';
		if (ptr->child[idx] == nullptr) {
			return 0;
		}
		ptr = ptr->child[idx];
	}
	if (ptr->isEnd) {
		return 1;
	}
	return 0;
}



int main() {
	int T, N, K, L;
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	for (int i = 0; i < T; ++i) {
		init();
		cin >> N >> K;
		// reading words of the language
		for (int i = 0; i < N; ++i) {
			cin >> word[i];
		}

		// reading the phrases:
		for (int i = 0; i < K; ++i) {
			cin >> L;
			for (int j = 0; j < L; ++j) {
				cin >> pWord;
				// insert the word in trie:
				insert(pWord);
			}
		}

		// Checking if word is present in any of the phrase:
		for (int i = 0; i < N; ++i) {
			if (searchWord(word[i])) {
				cout << "YES ";
			}
			else {
				cout << "NO ";
			}
		}
		cout << '\n';
	}
	return 0;
}