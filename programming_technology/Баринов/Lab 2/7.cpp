#include <iostream>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

template<class InIter, class OutIter>
OutIter my_copy(InIter first, InIter last, OutIter out);

template <typename InIter1, typename InIter2, typename OutIter>
OutIter my_set_difference(InIter1 first1, InIter1 last1, InIter2 first2, InIter2 last2, OutIter out);

int main() {

    vector <int> v{ 1,2,3,5,7,9 }, v2{ 1,2,6,9 }, v3(10);
    auto pred = [](int i) { return i % 2 == 0; };
    vector <int>::iterator new_end;

    new_end = my_set_difference(v.begin(), v.end(), v2.begin(), v2.end(), v3.begin());

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

template <typename InIter1, typename InIter2, typename OutIter>
OutIter my_set_difference(InIter1 first1, InIter1 last1, InIter2 first2, InIter2 last2, OutIter out) {

    while (first1 != last1) {
        if (first2 == last2) {
            return my_copy(first1, last1, out);
        }

        if (*first1 < *first2) {
            *out = *first1;
            first1++;
            out++;
        }
        else {
            if (!(*first2 < *first1))
                first1++;
            first2++;
        }
    }

    return out;

}