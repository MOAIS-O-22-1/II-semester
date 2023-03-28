//Ilyunkin Denis, MOAIS-O-22/1, var 8
#include <iostream>
#include <string>
#include <sstream>
//#include <iomanip>
using namespace std;

void slova(const string &s)
{
	string maslovo, mislovo, slovo;
	int max_ = 0, min_ = 1000;
	stringstream stream(s); //строковый поток
	while (stream) {
		stream >> slovo;
		if (slovo.length() > max_)
		{
			max_ = slovo.length();
			maslovo = slovo;
		}
		if (slovo.length() < min_)
		{
			min_ = slovo.length();
			mislovo = slovo;
		}
	}
	cout << "Самое короткое слово: " << mislovo << endl;
	cout << "Самое длинное слово: " << maslovo << endl;
}

int main()
{
	setlocale(LC_ALL, "rus");
	string s;
	getline(cin, s);
	slova(s);
}