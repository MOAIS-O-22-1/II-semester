#include <iostream>
#include <string>



using namespace std;
string ExtractDigits(const string& s)
{
	string newLine = "", digits = "0123456789"; 
	for (size_t i = 0; i < s.size(); i++)
	{
		if (digits.find(s[i]) != string::npos)
		{
			newLine += s[i];
		}
	}
	return newLine;
}

int main() 
{
	string s;

	getline(cin, s);

	cout << ExtractDigits(s) << endl;








}