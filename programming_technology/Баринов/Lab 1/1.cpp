#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

void hashing_with_deletion(unordered_set <string>& string_set, string& s, char& command);

int main() {

    unordered_set <string> string_set;
    string s;
    char command;

    hashing_with_deletion(string_set, s, command);

    return 0;

}

void hashing_with_deletion(unordered_set <string>& string_set, string& s, char& command) {

    while (cin >> command) {
        cin >> s;

        switch (command) {
        case '+': {
            string_set.insert(s);
            break;
        }
        case '-': {
            if (string_set.find(s) != string_set.end()) {
                string_set.erase(string_set.find(s));
            }
            break;
        }
        case '?':
            if (string_set.find(s) != string_set.end()) {
                cout << "YES" << endl;
            }
            else {
                cout << "NO" << endl;
            }
            break;
        }
    }

}