#include <iostream>
#include <cmath>
#include <algorithm>
#include <set>
#include <iomanip>

using namespace std;

int main() {

    int n;
    cin >> n;
    multiset <double> numbers;

    for (size_t i = 0; i < n; i++) {
        double tmp;
        cin >> tmp;
        numbers.insert(tmp);
    }
    double res;

    for (auto it = numbers.rbegin(); it != numbers.rend(); ++it) {
        if (it == numbers.rbegin()) res = *it;
        else res = 2 * sqrt(*it * res);
    }

    cout << fixed << setprecision(2) << res << endl;

    return 0;
}