#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

string join(const vector<string>& tokens, char delimiter);

int main() {

    setlocale(LC_ALL, "ru");

    const vector<string> tokens = { "What", "is", "your", "name?" };
    char delimiter = '_';

    cout << join(tokens, delimiter) << endl;

    system("pause");
    return 0;

}

string join(const vector<string>& tokens, char delimiter) {
    
    string str;
    for (string i : tokens) str += i + delimiter;
    str.pop_back();

    return str;

}