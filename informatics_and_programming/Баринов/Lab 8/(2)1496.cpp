#include <iostream>
#include <string>
#include <set>
#include <map>

using namespace std;

int main() {

	set <string> acc;
	set <string> sp;
	int n;
	cin >> n;
	
	for (size_t i = 0; i < n + 1; i++) {
		string tmp;
		getline(cin, tmp);
		if (acc.find(tmp) != acc.end()) sp.insert(tmp);
		acc.insert(tmp);
	}
	for (auto i : sp) cout << i << endl;

	return 0;

}