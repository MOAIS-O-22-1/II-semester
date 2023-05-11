#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

template <typename T> vector <T> FindGreaterElements(set <T> elements, T border);

int main() {

    for (int x : FindGreaterElements(set<int>{ 1, 5, 7, 8 }, 5)) {
        cout << x << " ";
    }
    cout << endl;

    string to_find = "Python";
    cout << FindGreaterElements(set<string>{ "C", "C++" }, to_find).size() << endl;

    return 0;

}

template <typename T> vector <T> FindGreaterElements(set <T> elements, T border) {

    vector <T> vector_large;

    auto it = find_if(elements.begin(), elements.end(), [border](T i) {return i > border; });

    for (it; it != elements.end(); it++) vector_large.push_back(*it);

    return vector_large;

}