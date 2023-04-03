#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

int main()
{
	unordered_set <string> arr;

	char symbol;
	string s;
	while (cin >> symbol)
	{


		if (symbol == '#') { break; }
		cin >> s;
		switch (symbol)
		{
		case '+': arr.insert(s); break;
		case '-':
			if (arr.count(s))
			{
				arr.erase(s);
			}
			break;
		case '?':
			if (arr.count(s))
			{
				cout << "YES" << endl;
			}
			else
			{
				cout << "NO" << endl;
			}
			break;
		}
	}


}