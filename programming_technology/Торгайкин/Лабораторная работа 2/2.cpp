#include <iostream>
#include <unordered_map>
#include <list>
#include <iterator>



using namespace std;


int main()
{
	unordered_map <int, list <int> ::iterator> dict;
	list <int> result;
	size_t n;
	int prev, next;


	cin >> n;
	cin >> next >> prev;

	result.push_back(next);
	dict[next] = result.begin();

	auto it = result.end();


	for (size_t i = 1; i < n; i++)
	{
		cin >> next >> prev;


		if (dict.count(prev))
		{
			it = dict.at(prev);
		}


		if (it == result.end())
		{
			result.insert(result.begin(), next);
			dict[next] = result.begin();
		}
		else
		{

			result.insert(++it, next);
			dict[next] = it;
		}

		it = result.end();

	}

	for (const auto& i : result)
	{
		cout << i << endl;
	}
}