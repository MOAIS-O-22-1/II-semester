#include <iostream>
#include <string>


using namespace std;

string common_suffix(const string& a, const string& b)
{
	string s;
	if (a == b) { return a; }
	for (size_t i = a.size() - 1; i > 0; i--)
	{
		
		if (b.find(a.substr(i)) != string::npos)
		{
			s = a.substr(i);
		}
	}
	return s;
}



int main()
{
	setlocale(LC_ALL, "Rus");
	string a, b;
	cout << "Введите первую строку: ";
	cin >> a;
	cout << "Введите вторую строку: ";
	cin >> b;
	cout << common_suffix(a, b) << endl;
}