#include <iostream>
#include <queue>
#include <string>

using namespace std;

priority_queue <int> main_queue;

template <typename It, typename Pred> bool my_any_of(It first, It last, Pred f);

int main() {

    vector <int> v{ 1,2,3,5,7,9 };
    auto pred = [](int i) { return i % 2 == 0; };
    cout << my_any_of(v.begin(), v.end(), pred) << endl;

    return 0;

}

template <typename It, typename Pred> bool my_any_of(It first, It last, Pred f) {

    for (auto elem = first; elem != last; elem++)
        if (f(*elem)) return true;

    return false;
}