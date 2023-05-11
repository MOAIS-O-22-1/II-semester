#include <iostream>
#include <map>
#include <set>
#include <string>

using namespace std;

void enter_words(map <char, int>& number_of_letters, int& words_count);
set <char> make_set(const string& word);
void print_result(const map <char, int>& number_of_letters, const int& words_count);

int main() {

    map <char, int> number_of_letters;
    int words_count = 0;

    enter_words(number_of_letters, words_count);

    print_result(number_of_letters, words_count);

    return 0;
}

void enter_words(map <char, int>& number_of_letters, int& words_count) {

    string word;
    while (cin >> word) {
        words_count++;
        set<char> letters_in_word = make_set(word);

        for (auto ch : letters_in_word) {
            number_of_letters[ch]++;
        }
    }

}

set <char> make_set(const string& word) {

    set<char> letters_in_word;
    for (auto ch : word) letters_in_word.insert(ch);

    return letters_in_word;

}

void print_result(const map <char, int>& number_of_letters, const int& words_count) {

    for (auto ch : number_of_letters) {
        if (ch.second == words_count) {
            cout << ch.first;
        }
    }
    cout << endl;

}