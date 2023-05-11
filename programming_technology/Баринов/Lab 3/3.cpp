#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

vector <string> SplitIntoWords (const string& s);

int main() {

    string s = "C Cpp Java Python";

    vector <string> words = SplitIntoWords(s);
    cout << words.size() << " ";
    for (auto it = words.begin(); it != words.end(); it++) {
        if (it != words.begin()) cout << "/";
        cout << *it;
    }
    cout << endl;

    return 0;

}

vector <string> SplitIntoWords(const string& s) {

    vector<string> words;

    auto it_begin = s.begin();
    auto it_end = find(it_begin, s.end(), ' ');

    while(it_end != s.end()) {
        words.push_back(string(it_begin, it_end));
        it_begin = it_end + 1;
        it_end = find(it_begin, s.end(), ' ');
    }
    words.push_back(string(it_begin, it_end));

    return words;

}