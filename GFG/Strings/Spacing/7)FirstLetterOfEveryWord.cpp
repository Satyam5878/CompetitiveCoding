/**
 *
 * String containing first letter of every word in a given string with spaces
 *
 **/
#include<iostream>

using namespace std;

void printFirstLetter(char *str) {
	if (str[0] != ' ') {
		cout << str[0];
	}
	for (int i = 0;str[i] != '\0';++i) {
		if (str[i] == ' ') {
			if (str[i + 1] != '\0' && str[i + 1] != ' ') {
				cout << str[i + 1];
			}
		}
	}
}

int main() {
	char *str = "geeks for geeks";
	printFirstLetter(str);

	return 0;
}