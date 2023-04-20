#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;








vector <string> Text3(const vector <vector<string>>& file, const string& output_performer, map <string, vector<string>>& dict)
{
	vector <string> performer;
	for (const auto& i : file)
	{
		if (i[0] == output_performer)
		{
			performer.push_back(i[1]);
		}

		dict[i[2]].push_back(i[1]);


	}
	return performer;
}




int main()
{

	setlocale(LC_ALL, "Rus");

	ifstream input_file;
	ofstream first_output_file;
	ofstream second_output_file;

	input_file.open("text1.txt");
	first_output_file.open("text2.txt");
	second_output_file.open("text3.txt");

	string output_performer;
	string s, t;

	cout << "Введите исполнителя: ";
	getline(cin, output_performer);
	vector <vector <string>> file;
	map <string, vector <string>> dict;
	vector <string> performer;

	while (getline(input_file, s))
	{

		stringstream str(s);
		while (str >> s)
		{
			
			if (s[s.size() - 1] != '»')
			{
				t += s + " ";

			}
			else
			{

				s = t + s;
			
				t = "";
				if (s[0] == '-')
				{
					s.erase(s.begin(), s.begin() + 3);
				}
				else
				{
					s.erase(s.begin(), s.begin() + 1);
				}


				s.erase(end(s) - 1, end(s));

				performer.push_back(s);
			}


		}


		file.push_back(performer);
		performer.clear();
	}

	performer = Text3(file, output_performer, dict);


	first_output_file << output_performer << " - "; // вывод в файл text2.txt
	for (const auto& i : performer)
	{
		if (i != performer[performer.size() - 1])
		{
			first_output_file << i << ", ";
		}
		else
		{
			first_output_file << i << endl;
		}
	}


	
	for (const auto& i : dict) // вывод в файл text3.txt
	{
		second_output_file << i.first << " - ";
		for (const auto& j : i.second)
		{
			if (j != i.second[i.second.size() - 1])
			{
				second_output_file << j << ", ";
			}
			else
			{
				second_output_file << j << endl;
			}
		}
	}
	input_file.close();
	first_output_file.close();
	second_output_file.close();
}