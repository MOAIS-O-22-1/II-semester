#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <set>

using namespace std;

map < string, vector<int> > make_words_map(const int& m, const int& n);
set <string> make_max_vec(map < string, vector<int> >& words_map, const int& n);
void print_vec(set <string>& max_vec);

int main() {

    int m, n;
    cin >> m >> n;

    map < string, vector<int> > words_map = make_words_map(m, n);

    set <string> max_vec = make_max_vec(words_map, n);
    
    print_vec(max_vec);

    return 0;

}

map < string, vector<int> > make_words_map(const int& m, const int& n) {

    map < string, vector<int> > words_map;

    for (size_t i = 0; i < m; i++) {
        string word;
        vector <int> vec;
        cin >> word;
        for (size_t j = 0; j < n; j++) {
            int a;
            cin >> a;
            vec.push_back(a);
        }
        words_map[word] = vec;
    }

    return words_map;
}

set <string> make_max_vec(map < string, vector<int> >& words_map, const int& n) {

    set <string> max_vec;
    int max_len = 0;
    size_t cnt = 0;
    auto it = words_map.begin();
    for (auto word : words_map) {
        if (cnt != 0) {
            int scalar = (*it).second[0] * word.second[0];
            for (size_t i = 1; i < n; i++) {
                scalar += (*it).second[i] * word.second[i];
            }
            if (max_len < scalar) {
                max_len = scalar;
                max_vec.clear();
                max_vec.insert(word.first);
            }
            else if (max_len == scalar) {
                max_vec.insert(word.first);
            }
        }
        cnt++;
    }

    return max_vec;

}

void print_vec(set <string>& max_vec) {

    for (auto i : max_vec) cout << i << endl;

}