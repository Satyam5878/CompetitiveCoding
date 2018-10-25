/**
 *
 * URLify a given string (Replace spaces is %20)
 *
 **/

#include<iostream>
#define MAX 100

using namespace std;
void printString(char *str) {
	cout << str;
}
void URLifyString(char *str) {
	// GEtting lenthe of string and count of spaces:
	int len = 0, space_count = 0,i;
	for (i = 0;str[i] != '\0';++i) {
		if (str[i] == ' ') {
			space_count++;
		}
	}
	// Removing the trailing spaces:
	while (str[i - 1] == ' ') {
		space_count--;
		i--;
	}
	// shifting the rest character by 3*sapce_count:
	str[i + space_count * 3-space_count] = '\0';
	i--;
	for (int j = i + space_count * 3;i >= 0;--i ) {
		if (str[i] == ' ') {
			str[j--] = '0';
			str[j--] = '2';
			str[j--] = '%';
		}
		else {
			str[j--] = str[i];
		}
	}
}

int main() {
	char str[MAX] = "Mr John Smith   ";
	URLifyString(str);
	printString(str);

	return 0;

}