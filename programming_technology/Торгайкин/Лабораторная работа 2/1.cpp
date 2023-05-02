#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <sstream>

using namespace std;





int main()
{

	string s, first_word;
	set <char> letters;
	vector <string> words;

	cin >> first_word;
	cin.ignore();
	bool flag = true;
	while (getline(cin, s) && !s.empty())
	{

		words.push_back(s);
	}

	for (const auto& i : first_word)
	{
		for (const auto& j : words)
		{
			if (j.find(i) == string::npos)
			{
				flag = false;
				break;
			}
		}
		if (flag)
		{
			letters.insert(i);
		}
		flag = true;
		
	}

	for (const auto& i : letters)
	{
		cout << i;
	}
}