#include <iostream>
#include <map>
#include <set>
#include <string>




using namespace std;

int main()
{
	int count = 0;
	string word;
	size_t key, n;
	map <size_t, set <string>> dict;

	cin >> n;

	for (size_t i = 0; i < n; i++)
	{
		cin >> word >> key;

		dict[key].insert(word);
	}

	for (const auto& i : dict)
	{
		cout << i.first << " ";
		for (const auto& j : i.second)
		{

			if (count == i.second.size() - 1)
			{
				cout << j << endl;
			}
			else
			{
				cout << j << " ";
			}
			count += 1;
		}
		count = 0;
	}

}