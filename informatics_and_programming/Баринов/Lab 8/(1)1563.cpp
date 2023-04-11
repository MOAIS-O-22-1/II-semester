#include <iostream>
#include <string>
#include <set>
#include <map>

using namespace std;

int main() {

	set <string> shops;
	int n;
	cin >> n;

	for (size_t i = 0; i < n + 1; i++) {
		string tmp;
		getline(cin, tmp);
		shops.insert(tmp);
	}

	cout << n + 1 - shops.size() << endl;

	return 0;

}