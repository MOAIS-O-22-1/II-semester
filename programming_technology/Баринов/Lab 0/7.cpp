#include <iostream>
#include <vector>
#include <random>

uint32_t seed = 0;

using namespace std;

bool prime(int& n);
bool is_true(int& a, int& b, int& c);
vector <int> make_vector();
void fun(vector <int>& numbers);

int main() {

    vector <int> numbers = make_vector();
    fun(numbers);

    system("pause");
    return 0;

}

bool prime(int& n) {
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;
    return true;
}

bool is_true(int& a, int& b, int& c) {
    if (b > a && b > c) return true;
    else return false;
}

vector <int> make_vector() {
    vector<int> numbers;
    mt19937 mersenne(seed);
    uniform_int_distribution <int> distrib( -3200, 3200 );

    do {
        numbers.push_back(distrib(mersenne));
    } while (distrib(mersenne) != 0);
    numbers.push_back(0);

    cout << "Initial vector: " << endl;
    for (int i = 0; i <= numbers.size() - 1; i++) cout << numbers[i] << ' ';
    cout << endl;

    return numbers;
}

void fun(vector <int>& numbers) {
    int cnt = 0;
    for (size_t i = 1; i < numbers.size() - 2; i++) {
        if (prime(numbers[i]) && is_true(numbers[i - 1], numbers[i], numbers[i + 1]))
            cnt++;
    }
    cout << "Count of numbers by condition: " << cnt << endl;
}