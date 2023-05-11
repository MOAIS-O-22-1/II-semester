#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename RandomIt> 
void MergeSort(RandomIt range_begin, RandomIt range_end);

int main() {
    
    vector<int> v = { 6, 4, 7, 6, 4, 4, 0, 1 };
    MergeSort(v.begin(), v.end());
    for (int x : v) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}

template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end) {

    if (range_begin + 1 >= range_end) return;

    else {
        vector <typename RandomIt::value_type> elements(range_begin, range_end);
        auto it_mid = elements.begin() + elements.size() / 2;
        MergeSort(elements.begin(), it_mid);
        MergeSort(it_mid, elements.end());
        merge(elements.begin(), it_mid, it_mid, elements.end(), range_begin);
    }

}