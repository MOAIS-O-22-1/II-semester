// Вариант 3

#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>

using namespace std;

void fun(string s);

int main() {

    setlocale(LC_ALL, "ru");

    string s;
    getline(cin, s);

    fun(s);

    system("pause");
    return 0;

}

void fun(string s) {

    string s1 = s;
    s1.erase(remove(s1.begin(), s1.end(), ','), s1.end());
    cout << "Измененная строка: " << s1 << endl;
    cout << "Количество удаленных символов = " << s.size() - s1.size() << endl;

}

// ajchkakcjkac,ackhkslvksv,,,,skjhvkjsv,svkj,v,v,v,v,vjklvklsev,,,