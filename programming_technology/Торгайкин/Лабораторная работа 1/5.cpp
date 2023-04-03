#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <utility>

using namespace std;


void ALL_BUSES(const map<string, vector <string>>& sort_bus_routes)
{
	if (sort_bus_routes.size() == 0)
	{
		cout << "No buses" << endl;
	}
	else
	{
		for (const auto& i : sort_bus_routes)
		{
			cout << "Bus " << i.first << ": ";
			for (const auto& j : i.second)
			{
				cout << j << " ";
			}
			cout << endl;
		}
	}
}

void NEW_BUS(map <string, vector <string>>& sort_bus_routes, vector <pair<string, vector <string>>>& bus_routes)
{
	size_t stop_count;
	string bus, stop;
	vector <string> route;
	pair <string, vector <string>> bus_route;

	cin >> bus >> stop_count;

	for (size_t i = 0; i < stop_count; i++)
	{
		cin >> stop;
		route.push_back(stop);

	}
	sort_bus_routes[bus] = route;
	bus_route.first = bus;
	bus_route.second = route;
	bus_routes.push_back(bus_route);
}

void BUSES_FOR_STOP(const vector <pair <string, vector <string>>>& bus_routes)
{
	string stop;
	cin >> stop;
	bool flag = true;
	for (const auto& i : bus_routes)
	{
		for (const auto& j : i.second)
		{
			if (j == stop)
			{
				cout << i.first << " ";
				flag = false;
				break;
			}
		}

	}

	if (flag)
	{
		cout << "No stop";
	}
	cout << endl;
}

void STOPS_FOR_BUS(const vector <pair <string, vector <string>>>& bus_routes)
{
	string bus;
	vector <string> routes;
	bool flag1 = true, flag2 = true;
	cin >> bus;

	for (const auto& i : bus_routes)
	{
		if (i.first == bus)
		{
			flag1 = false;
			break;
		}
	}
	if (flag1)
	{
		cout << "No bus" << endl;
	}
	else
	{
		for (const auto& i : bus_routes)
		{
			if (i.first == bus)
			{
				for (const auto& j : i.second)
				{
					routes.push_back(j);
				}
				break;
			}
		}

		for (const auto& i : routes)
		{
			cout << "Stop " << i << ": ";
			for (const auto& j : bus_routes)
			{

				for (const auto& k : j.second)
				{

					if (i == k && j.first != bus)
					{
						flag2 = false;
						cout << j.first << " ";
						break;
					}

				}
			}
			if (flag2)
			{
				cout << "no interchange";
			}
			flag2 = true;

			cout << endl;
		}
	}




	




}




int main()
{
	size_t n;
	map <string, vector <string>> sort_bus_routes;
	vector <pair<string, vector <string>>> bus_routes;
	string request;

	cin >> n;
	for (size_t i = 0; i < n; i++)
	{
		cin >> request;
		switch (request[0])
		{
		case 'N': NEW_BUS(sort_bus_routes, bus_routes); break;
		case 'B': BUSES_FOR_STOP(bus_routes); break;
		case 'S': STOPS_FOR_BUS(bus_routes); break;
		case 'A': ALL_BUSES(sort_bus_routes); break;
		}
	}

}