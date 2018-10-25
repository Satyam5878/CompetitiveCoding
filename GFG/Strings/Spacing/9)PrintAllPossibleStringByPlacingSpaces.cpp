/**
 *
 * Print all possible strings that can be made by placing spaces
 *
 **/

#include<iostream>
#include<ctime>
#define start_time_routine  clock_t start_time = clock();
#define end_time_routine clock_t end_time = clock(); \
        double time_elapsed = double(end_time-start_time)/CLOCKS_PER_SEC;\
        printf("%.3f",time_elapsed);\



using namespace std;
// Function to print all possible string with spaces:
inline void printBuffer(char *buff, int buffIdx) {
	for (int i = 0;i < buffIdx;++i) {
		cout << buff[i];
	}
	cout << endl;
}
inline void printAllPossibleString_rec(char *str, char *buff, int len, int strIdx,int buffIdx) {
	if (strIdx < len) {
		// calling for only character:
		buff[buffIdx++] = str[strIdx++];
		printAllPossibleString_rec(str, buff, len, strIdx, buffIdx);
		// calling for character followed by space:
		// should not be called for last character:
		if (strIdx != len) {
			buff[buffIdx++] = ' ';
			printAllPossibleString_rec(str, buff, len, strIdx, buffIdx);
		}
	}
	else {
		printBuffer(buff, buffIdx);
	}
}
inline void printAllPossibleString(char *str) {
	int len = 0;
	// getting length:
	for (int i = 0;str[i] != 0;++i) {
		len++;
	}
	char *buffer = new char[2 * len + 2];
	printAllPossibleString_rec(str, buffer, len, 0,0);
}

int main() {
	start_time_routine;
	char *str = "ABCDEFGHIJKLMN";
	printAllPossibleString(str);
	end_time_routine;
	return 0;
}