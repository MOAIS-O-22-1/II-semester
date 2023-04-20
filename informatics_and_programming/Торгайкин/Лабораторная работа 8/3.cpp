#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;
pair<int, string> old(const string& s)
{
	pair <int, string> carta;
	carta.second = s;
	switch (s[0])
	{
	case 'т': carta.first = 1; break;
	case '2': carta.first = 2; break;
	case '3': carta.first = 3; break;
	case '4': carta.first = 4; break;
	case '5': carta.first = 5; break;
	case '6': carta.first = 6; break;
	case '7': carta.first = 7; break;
	case '8': carta.first = 8; break;
	case '9': carta.first = 9; break;
	case '1': carta.first = 10; break;
	case 'в': carta.first = 11; break;
	case 'д': carta.first = 12; break;
	case 'к': carta.first = 13; break;
	}
	return carta;
}
bool f(pair <int, string> s1, pair <int, string> s2)
{
	if (s1.first < s2.first)
	{
		return s1 < s2;
	}
	else
	{
		return 0;
	}
}
int main()
{

	setlocale(LC_ALL, "Rus");

	ifstream input_file;

	input_file.open("text1.txt");
	string s;
	string t;

	vector <pair<string, vector <pair<int, string>>>> koloda(4);

	while (getline(input_file, s))
	{

		stringstream str(s);
		while (str >> s)
		{
			if (s != "-")
			{

				if (s == "червы")
				{
					koloda[0].first = "червы";

				}
				else if (s == "трефы")
				{
					koloda[1].first = "трефы";
				}
				else if (s == "бубны")
				{
					koloda[2].first = "бубны";
				}
				else if (s == "пики")
				{
					koloda[3].first = "пики";
				}
				else
				{
					if (t == "червы")
					{
						koloda[0].second.push_back(old(s));
					}
					else if (t == "трефы")
					{
						koloda[1].second.push_back(old(s));
					}
					else if (t == "бубны")
					{
						koloda[2].second.push_back(old(s));
					}
					else if (t == "пики")
					{
						koloda[3].second.push_back(old(s));
					}

				}
				t = s;
			}
		}

	}

	for (auto& i : koloda)
	{
		cout << i.first << " - ";
		sort(i.second.begin(), i.second.end(), f);
		for (const auto& j : i.second)
		{

			cout << j.second << " ";
		}
		cout << endl;
	}

	input_file.close();
}