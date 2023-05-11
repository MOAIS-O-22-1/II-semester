#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <iomanip>

using namespace std;

string make_expression();

int main() {

    string expression = make_expression();

    cout << expression << endl;

    return 0;
}

string make_expression() {

    int number, n;
    cin >> number >> n;
    string expression = to_string(number);

    for (size_t i = 0; i < n; i++) {
        char ch;
        cin >> ch >> number;
        if (number >= 0) expression = '(' + expression + ')' + ' ' + ch + ' ' + to_string(number);
        else expression = '(' + expression + ')' + ' ' + ch + ' ' + '(' + to_string(number) + ')';
    }

    return expression;

}