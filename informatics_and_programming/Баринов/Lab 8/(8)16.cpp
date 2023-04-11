#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

vector <string> make_vector();
void counting(const vector <string>& names, const int& n);

int main() {

    string sn;
    getline(fin, sn);
    int n = stoi(sn);

    vector <string> names = make_vector();

    counting(names, n);

    return 0;

}

vector <string> make_vector() {
    
    vector <string> names;
    string s;
    while (getline(fin, s)) {
        names.push_back(s);
    }

    return names;

}

void counting(const vector <string>& names, const int& n) {

    int step = n - 1;
    if (names.size() % n == 0) {
        int count = 1;
        for (size_t i = 0; i < names.size(); i++) {
            if (step > names.size() - 1) {
                count++;
                step = n - count;
            }
            fout << names[step] << endl;
            step += n;
        }
    }
    else {
        for (size_t i = 0; i < names.size(); i++) {
            if (step > names.size() - 1) step = step - names.size();
            fout << names[step] << endl;
            step += n;
        }
    }

}