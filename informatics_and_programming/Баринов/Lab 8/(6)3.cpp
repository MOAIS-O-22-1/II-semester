#include <iostream>
#include <set>
#include <string>
#include <fstream>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

set <char> make_letter_list();
void exam(set <char>& letters);
void print_set(const set <char>& letters);

int main() {

    set <char> letters = make_letter_list();
    
    exam(letters);

    print_set(letters);
    
    return 0;

}

set <char> make_letter_list() {

    set <char> letters;
    for (char i = 'A'; i <= 'Z'; i++) {
        letters.insert(i);
    }

    return letters;

}

void exam(set <char>& letters) {
    
    string s;
    while (getline(fin, s)) {
        for (auto ch : s) {
            if (letters.find(ch) != letters.end()) {
                letters.erase(ch);
            }
            else if (letters.find(ch - 32) != letters.end()) {
                letters.erase(ch - 32);
            }
        }
    }

}

void print_set(const set <char>& letters) {
    for (auto ch : letters) fout << ch << " ";
}