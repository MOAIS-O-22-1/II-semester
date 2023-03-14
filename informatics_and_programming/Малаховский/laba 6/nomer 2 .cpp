#include <iostream>
#include <string>
using namespace std;

int func(string s) {
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == ' ') {
			s.erase(i, 1);
		}
	}
	return s.size();
}
int main() {
	string s;
	getline(cin, s);
	cout << func(s);
	return 0;
}