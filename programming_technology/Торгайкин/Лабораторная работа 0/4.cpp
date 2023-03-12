#include <iostream>
#include <string>
#include <vector>


using namespace std;

vector<string> Split(const string& str, char delimiter)
{
	vector <string> words;
	string word = "";
	for (size_t i = 0; i < str.size(); i++)
	{
		if (str[i] != delimiter)
		{
			word += str[i];
		}
		else
		{
			words.push_back(word);
			word = "";
		}
	}
	words.push_back(word);
	return words;
}

int main()
{
	setlocale(LC_ALL, "Rus");
	vector <string> words;
	string str;
	char delimiter;
	cout << "Введите строку: ";
	getline(cin, str);
	cout << "Введите разделитель:";
	cin >> delimiter;
	words = Split(str, delimiter);
	for (size_t i = 0; i < words.size(); i++)
	{
		cout << words[i] << endl;
	}
}