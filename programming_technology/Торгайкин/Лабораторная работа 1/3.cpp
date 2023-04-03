#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>

using namespace std;


bool fun(pair <string, int>& s1, pair <string, int>& s2)
{
	if (s1.second > s2.second)
	{
		return s1.second > s2.second;
	}
	else
	{
		return 0;
	}
}





int main()
{
	size_t n, m;
	int sum = 0, num, min;
	vector <pair <string, int>> dict;
	pair <string, vector <int>> first_word;
	pair <string, int> word;
	vector <int> cord;
	string key;

	cin >> m >> n;
	for (size_t i = 0; i < m; i++)
	{
		if (i == 0)
		{
			cin >> key;
			for (size_t j = 0; j < n; j++)
			{
				cin >> num;
				cord.push_back(num);
			}
			first_word.first = key;
			first_word.second = cord;
			cord.clear();

		}
		else
		{
			cin >> key;
			for (size_t j = 0; j < n; j++)
			{
				cin >> num;
				cord.push_back(num);

			}
			for (size_t k = 0; k < n; k++)
			{
				sum += cord[k] * first_word.second[k];
			}
			word.first = key;
			word.second = sum;
			dict.push_back(word);
			cord.clear();
			sum = 0;

		}
	}

	sort(dict.begin(), dict.end(), fun);

	min = dict[0].second;
	for (const auto& i : dict)
	{
		if (i.second == min)
		{
			cout << i.first << endl;
		}
		else
		{
			break;
		}
	}
}