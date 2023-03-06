#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

vector<string> split(const string & str, char delimiter);

int main() {

    setlocale(LC_ALL, "ru");

    string str;
    char delimiter;
    vector<string> split_string;

    cout << "Введите строку: ";
    getline(cin, str);

    cout << "Введите делитель: ";
    cin >> delimiter;

    split_string = split(str, delimiter);
    cout << "Преобразованная строка: " << endl;
    for (auto s : split_string) {
        cout << s << endl;
    }

    system("pause");
    return 0;

}

vector<string> split(const string& str, char delimiter) {
    
    string word = "";
    vector<string> split_string;
    for (size_t i = 0; i < str.size(); i++) {
        if (str[i] == delimiter) {
            split_string.push_back(word);
            word = "";
        }
        else word += str[i];
    }
    split_string.push_back(word);

    return split_string;

}