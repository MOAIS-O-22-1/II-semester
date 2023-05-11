#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

template <typename T> void printVector(T vec);
vector <int> enterVector();
void allPermutations(vector <int>& numbers);

int main() {
    
    vector <int> numbers = enterVector();

    allPermutations(numbers);

    return 0;
}

template <typename T> void printVector(T vec) {
    for (auto i : vec) cout << i << " ";
}

vector <int> enterVector() {

    int N;
    cin >> N;
    vector <int> numbers;
    for (int i = N; i > 0; i--) numbers.push_back(i);

    return numbers;

}

void allPermutations(vector <int>& numbers) {

    do {
        printVector(numbers);
        cout << endl;
    } while (prev_permutation(numbers.begin(), numbers.end()));

}