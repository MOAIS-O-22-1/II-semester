#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T>
void RemoveDuplicates(T& elements);

int main() {
    
    vector <int> v1 = { 6,4,7,6,4,4,0,1 };
    RemoveDuplicates(v1);
    for (int x : v1) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}

template <typename T>
void RemoveDuplicates(T& elements) {

    sort(elements.begin(), elements.end());
    elements.erase(unique(elements.begin(), elements.end()), elements.end());

}