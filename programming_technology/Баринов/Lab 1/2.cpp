#include <iostream>
#include <map>
#include <string>

using namespace std;

multimap <int, string> make_map(int& n);
void print_res(multimap <int, string>& book);

int main() {

    int n = 0;
    cin >> n;

    multimap <int, string> book = make_map(n);

    print_res(book);

    return 0;

}

multimap <int, string> make_map(int& n) {

    multimap <int, string> book;
    for (size_t i = 0; i < n; i++) {
        pair <int, string> tmp;
        cin >> tmp.second >> tmp.first;
        book.insert(tmp);
    }

    return book;

}

void print_res(multimap <int, string>& book) {

    pair <int, string> tmp;
    for (auto it = book.begin(); it != book.end(); it++) {
        if (tmp.first != (*it).first && tmp.second != (*it).second) {
            if (book.find((*it).first) == it) {
                cout << endl << (*it).first << " " << (*it).second << " ";
            }
            else {
                tmp.first = (*it).first;
                tmp.second = (*it).second;
                cout << (*it).second << " ";
            }
        }
    }

}