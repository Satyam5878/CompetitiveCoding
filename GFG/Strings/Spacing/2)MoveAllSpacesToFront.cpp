/**
 *
 * Move spaces to front of string in single traversal
 *
 **/
#include<iostream>

using namespace std;

// function to move spaces to front:
// Using swapping:
void moveSpacesToBegining(char *str) {
	// Get the length of string:
	int len = 0;
	for (int i = 0;str[i] != '\0';++i) {
		len++;
	}
	// moving spaces to front:
	int i = len - 1;
	volatile int j = len - 1;
	char c;
	while (i >= 0) {
		if (str[i] != ' ') {
			c = str[i];
			str[i] = str[j];
			str[j] = c;
			j--;
		}
		--i;
	}
}

// Without Using Swapping:
void moveSpacesToBegining2(char *str) {
	// Get the length of string:
	int len = 0;
	for (int i = 0;str[i] != '\0';++i) {
		len++;
	}
	// Move spaces to beginning:
	int i = len - 1;
	int j = len - 1;
	while (i >= 0) {
		if (str[i] != ' ') {
			str[j--] = str[i];
		}
		i--;

	}
	while (j >= 0) {
		str[j--] = ' ';
	}
}

void printArray(char *str) {
	cout << str<<endl;
}


int main() {
	char str[] = "move these spaces to beginning";
	/*printArray(str);
	moveSpacesToBegining(str);
	printArray(str);*/
	printArray(str);
	moveSpacesToBegining2(str);
	printArray(str);

}