#include <iostream>
#include <vector>
#include <string>


using namespace std;



string Join(const vector<string>& tokens, char delimiter)
{
	string str = "";
	for (size_t i = 0; i < tokens.size(); i++)
	{
		if (i != tokens.size() - 1)
		{
		str += tokens[i] + delimiter;
		}
		else { str += tokens[i]; }
	}
	return str;
}

int main()
{
	setlocale(LC_ALL, "Rus");
	char delimiter;
	string s, word = "";
	vector <string> tokens;
	cout << "Введите строку: " << std::endl;
	getline(cin, s);
	cout << "Введите разделитель" << std::endl;
	cin >> delimiter;
	for (size_t i = 0; i < s.size(); i++)
	{
		if (s[i] != ' ')
		{
			word += s[i];
		}
		else
		{
			tokens.push_back(word);
			word = "";
		}
	}
	if (word.size() != 0) { tokens.push_back(word); }

	cout << Join(tokens, delimiter);
	
}