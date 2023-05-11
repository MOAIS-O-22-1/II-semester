#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

using namespace std;

void fun(vector <int>& previous, vector <int>& next, const int& n, int& first);
void print_res(vector <int>& next, int& first);

int main() {

    int k = 1000000;
    int n;
    cin >> n;

    vector <int> previous(k, -1), next(k, -1);
    int first = -1;


    fun(previous, next, n, first);

    print_res(next, first);

    return 0;

}

void fun(vector <int>& previous, vector <int>& next, const int& n, int& first) {

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;

        if ((first != b) && (previous[b] == -1)) {
            if (first != -1) previous[first] = a;
            next[a] = first;
            first = a;

        }
        else {
            previous[a] = b;
            if (next[b] != -1)previous[next[b]] = a;
            next[a] = next[b];
            next[b] = a;
        }
    }

}

void print_res(vector <int>& next, int& first) {

    while (true) {
        cout << first << ' ';
        if (next[first] == -1) break;
        first = next[first];
    }

}