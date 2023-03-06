#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string common_suffix(const string & a, const string& b);

int main() {

    setlocale(LC_ALL, "ru");
    
    string a, b;
    cout << "¬ведите первое слово: ";
    cin >> a;
    cout << "¬ведите второе слово: ";
    cin >> b;

    cout << common_suffix(a, b) << endl;

    system("pause");
    return 0;

}

string common_suffix(const string& a, const string& b) {

    string suffix  = "";
    for (pair <size_t, size_t> i ((a.size() - 1), (b.size() - 1)); i.first >= 0, i.second >= 0; i.first--, i.second--) {
        if (a[i.first] == b[i.second]) suffix = a[i.first] + suffix;
        else return suffix;
    }

}