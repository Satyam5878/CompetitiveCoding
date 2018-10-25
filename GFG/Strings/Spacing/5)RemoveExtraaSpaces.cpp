/**
 *
 * Remove extra spaces from a string
 *
 **/

#include<iostream>

using namespace std;

// function to remove extra spaces:
void removeExtraSpaces(char *str) {
	int i = 0, j = 0, k = 0;
	// move till end
	while (str[i] != '\0') {
		// if not a space copy it to its original place
		if (str[i] != ' ') {
			str[k++] = str[i];
		}
		// if space
		else{
			// fin the last index of continuous space
			j = i + 1;
			while (str[j] == ' ') {
				j++;
			}
			// if reached to end than stop
			if (str[j] == '\0') {
				str[k] = '\0';
				break;
			}
			// if not then check if '.' '?' ',' 
			else if (str[j] == '.' || str[j] == '?' || str[j] == ',') {
				str[k++] = str[j];
				i = j;
			}
			// else put space and next char
			else {
				if(i!=0)
					str[k++] = ' ';
				str[k++] = str[j];
				i = j;
			}
		}

		i++;
	}

}

int main() {
	char str[] = "   Hello Geeks . Welcome   to  GeeksforGeeks   .    ";
	cout << str << endl;
	removeExtraSpaces(str);
	cout << str << endl;
	return 0;
}