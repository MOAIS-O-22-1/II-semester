#include <iostream>
#include <string>



using namespace std;



// Kaldfs Udfsf uioq hgfri acvbn Bqwerty

void deleteWord(const string& s)
{
	string newS, word, vowLet = "AaOoYyEeIiUu";

	for (size_t i = 0; i < s.size(); i++)
	{
		if (s[i] != ' ')
		{
			word += s[i];
		}
		else {
			if (vowLet.find(word[0]) != string::npos)
			{
				word = "";
			}
			else
			{
				newS += word + " ";
				word = "";
			}
		}
	}
	if (vowLet.find(word[0]) == string::npos) { newS += word + " "; }

	cout << "Новая строка: " << newS << endl;

}
int main()
{
	setlocale(LC_ALL, "Rus");
	string s;
	cout << "Введите строку: ";
	getline(cin, s);
	deleteWord(s);
}