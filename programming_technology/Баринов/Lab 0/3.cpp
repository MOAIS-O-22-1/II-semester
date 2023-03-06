#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool condition(int value);
string extract_digits(const string & s);

int main() {

    setlocale(LC_ALL, "ru");

    string s;
    cout << "Введите строку: ";
    getline(cin, s);

    cout << "Преобразованная строка: " << extract_digits(s) << endl;

    system("pause");
    return 0;

}

bool condition(int value)
{
    return value > '9';
}

string extract_digits(const string& s) {
    
    string s1 = s;
    s1.erase(remove_if(s1.begin(), s1.end(), condition), s1.end());
    return s1;

}