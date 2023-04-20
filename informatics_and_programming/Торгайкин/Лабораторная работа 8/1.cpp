#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <string>
#include <sstream>


using namespace std;


int main()
{
	setlocale(LC_ALL, "Rus");
	ifstream input_file;
	ofstream output_file;
	input_file.open("text1.txt");
	output_file.open("text2.txt");
	map <string, vector <string>> people_and_phone;
	string s;

	while (getline(input_file, s))
	{
		stringstream str(s);
		string fio;
		bool flag = 0;
		while (str >> s)
		{

			if (flag)
			{
				people_and_phone[fio].push_back(s);
			}
			if (s != "-" && flag == 0)
			{
				fio += s + " ";

			}
			else
			{
				flag = 1;
			}
			

		}
	}

	for (const auto& i : people_and_phone)
	{
		output_file << i.first << "- ";
		for (const auto& j : i.second)
		{
			if (j == i.second[i.second.size() - 1])
			{
				output_file << j << endl;
			}
			else
			{
				output_file << j << ", ";
			}
		}
	}
	input_file.close();
	output_file.close();

}