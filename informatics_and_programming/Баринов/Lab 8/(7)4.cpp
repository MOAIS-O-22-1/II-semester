#include <iostream>
#include <map>
#include <set>
#include <string>
#include <fstream>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

map <string, int> make_map();
set <pair <string, int>> search_max_words(const map <string, int>& words);
void print_set(const set <pair <string, int>>& max_words);

int main() {

    map <string, int> words = make_map();

    set <pair <string, int>> max_words = search_max_words(words);

    print_set(max_words);

    return 0;

}

map <string, int> make_map() {

    map <string, int> words;
    string s;
    while (fin >> s) {
        if (words.find(s) == words.end()) words[s] = 1;
        else words[s] += 1;
    }

    return words;

}

set <pair <string, int>> search_max_words(const map <string, int>& words) {

    set <pair <string, int>> max_words;
    max_words.insert(*words.begin());
    for (auto word : words) {
        if ((*max_words.begin()).second < word.second) {
            max_words.clear();
            max_words.insert(word);
        }
        else if ((*max_words.begin()).second == word.second) {
            max_words.insert(word);
        }
    }

    return max_words;

}

void print_set(const set <pair <string, int>>& max_words) {
    for (auto word : max_words) fout << word.first << " ";
}