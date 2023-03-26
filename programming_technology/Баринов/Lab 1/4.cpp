#include <iostream>
#include <vector>

using namespace std;

vector <int> make_vector(const int& n);
void print_min_num(vector <int>& numbers, const int& n, const int& k);

int main() {

    int n, k;
    cin >> n >> k;

    vector <int> numbers = make_vector(n);

    print_min_num(numbers, n, k);

    return 0;

}

vector <int> make_vector(const int& n) {

    vector <int> numbers;

    for (size_t i = 0; i < n; i++) {
        int a;
        cin >> a;
        numbers.push_back(a);
    }

    return numbers;

}

void print_min_num(vector <int>& numbers, const int& n, const int& k) {

    for (size_t i = 0; i < n - k + 1; i++) {
        int min_num = numbers[i];
        for (size_t j = 1; j < k; j++) {
            min_num = min(min_num, numbers[i + j]);
        }
        cout << min_num << endl;
    }

}