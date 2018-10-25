#include<iostream>
#include<string>
#include<sstream>

using namespace std;

void removeSpaces(string s) {
	stringstream ss;
	string tmp;
	ss << s;
	s = "";
	while (!ss.eof()) {
		ss >> tmp;
		s =  s + tmp;
	}
	cout << s;
}

int main() {
	string s = "This is a test";
	removeSpaces(s);

}