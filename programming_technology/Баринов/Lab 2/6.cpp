#include <iostream>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

template <typename InIter, typename OutIter, typename Predicate>
OutIter my_remove_copy_if(InIter first, InIter last, OutIter out, Predicate f);

int main() {

    vector <int> v{ 1,2,3,5,7,9 }, v2(10);
    auto pred = [](int i) { return i % 2 == 0; };
    vector <int>::iterator new_end;

    new_end = my_remove_copy_if(v.begin(), v.end(), v2.begin(), pred);

    for (auto i : v2)
        cout << i << " ";

    return 0;

}

template <typename InIter, typename OutIter, typename Predicate> 
OutIter my_remove_copy_if(InIter first, InIter last, OutIter out, Predicate f) {

    for (auto elem = first; elem != last; elem++) {
        if (!f(*elem)) {
            *out = *elem;
            out++;
        }
    }

    return out;

}