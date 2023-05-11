#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename RandomIt> 
void MergeSort(RandomIt range_begin, RandomIt range_end);

int main() {
    
    vector<int> v = { 6, 4, 7, 6, 4, 4, 0, 1, 5 };
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

        auto it_first = elements.begin() + elements.size() / 3;
        auto it_second = elements.begin() + elements.size() / 3 * 2;

        MergeSort(elements.begin(), it_first);
        MergeSort(it_first, it_second);
        MergeSort(it_second, elements.end());

        vector <typename RandomIt::value_type> tmp;

        merge(elements.begin(), it_first, it_first, it_second, back_inserter(tmp));
        merge(tmp.begin(), tmp.end(), it_second, elements.end(), range_begin);
    }

}