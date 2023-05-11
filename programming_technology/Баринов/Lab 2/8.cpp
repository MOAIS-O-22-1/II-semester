#include <iostream>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

template<class InIter, class OutIter>
OutIter my_copy(InIter first, InIter last, OutIter out);

template <typename It, typename OutputIt>
OutputIt my_sideways_merge(It first1, It last1, It first2, It last2, OutputIt out);

int main() {

    vector <int> v{ 1,2,3,5,7,9,12 }, v2{ 10,9,6,2,1 }, v3(20);
    auto pred = [](int i) { return i % 2 == 0; };
    vector <int>::iterator new_end;

    new_end = my_sideways_merge(v.begin(), v.end(), v2.begin(), v2.end(), v3.begin());
    
    for (auto i : v3)
        cout << i << " ";

    return 0;

}

template<class InIter, class OutIter>
OutIter my_copy(InIter first, InIter last, OutIter out) {

    for (auto it = first; it != last; it++) {
        *out = *it;
        out++;
    }

    return out;

}

template <typename It, typename OutputIt>
OutputIt my_sideways_merge(It first1, It last1, It first2, It last2, OutputIt out) {

    last2--;

    while (first1 != last1) {
        if (first2 == last2)
            return my_copy(first1, last1, out);

        if (*last2 < *first1) {
            *out = *last2;
            last2--;
            out++;
        }

        else {
            *out = *first1;
            first1++;
            out++;
        }

        if (*first2 <= *first1 && first2 == last2) {
            *out = *last2;
            out++;
        }
    }

    return my_copy(first2, last2, out);

}