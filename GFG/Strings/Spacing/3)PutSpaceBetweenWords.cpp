#include<iostream>
#include<string>

using namespace std;

// Directly Printing the string:
void putSpaces(string str) {
	int x = 0;
	for (char c : str) {
		if (x != 0 &&c >= 'A' && c <= 'Z') {
			cout << " " << (char)(c - 'A' + 'a');
		}
		else if (x == 0) {
			cout << (char)(c - 'A' + 'a');
			x++;
		}
		else {
			cout << c;
			
		}
	}
}

string putSpaces_ret(string str) {
	string tmp;
	tmp.insert(tmp.end(),str[0] - 'A' + 'a');
	for (auto i = 1;i < str.size();++i) {
		if (str[i] >= 'A' && str[i] <= 'Z') {
			tmp.insert(tmp.end(), ' ');
			tmp.insert(tmp.end(), str[i] - 'A' + 'a');
		}
		else {
			tmp.insert(tmp.end(),str[i]);
		}
	}
	return tmp;
}

int main() {
	string str = "BruceWayneIsBatman";
	cout<<putSpaces_ret(str);
	return 0;
}