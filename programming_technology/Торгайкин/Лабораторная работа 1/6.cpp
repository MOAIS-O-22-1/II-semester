#include <iostream>
#include <string>
#include <set>
#include <map>

using namespace std;


int main()
{
	size_t n, count_stops;
	map <set <string>, int> dict;
	set <string> stops;
	string stop;

	cin >> n;

	for (size_t i = 0; i < n; i++)
	{
		cin >> count_stops;
		for (size_t j = 0; j < count_stops; j++)
		{
			cin >> stop;
			stops.insert(stop);
		}
		if (dict.count(stops) == 0)
		{
			dict[stops] = dict.size() + 1;
			cout << "New bus " << dict[stops] << endl;
		}
		else
		{
			cout << "Already exists for " << dict[stops]  << endl;
		}
		stops.clear();

	}

}