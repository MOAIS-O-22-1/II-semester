#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void PrintVectorPart(vector <int> numbers);

int main() {

    PrintVectorPart({ 6,1,8,-5,4 });
    cout << endl;
    PrintVectorPart({ -6,1,8,-5,4 });
    cout << endl;
    PrintVectorPart({ 6,1,8,5,4 });
    cout << endl;

    return 0;

}

void PrintVectorPart(vector <int> numbers) {

    auto it = find_if(numbers.begin(), numbers.end(), [](int i) { return i < 0; });
    if (it == numbers.begin()) return;
    else {
        it--;
        for (it; it != numbers.begin(); it--) cout << *it << " ";
        cout << *it;
    }

    /*auto it = numbers.begin();
    if (*it < 0) return;
    else {
        for (it; it != numbers.end(); it++) {
            if (*it < 0) {
                break;
            }
        }
        it--;
        for (it; it != numbers.begin(); it--) cout << *it << " ";
        cout << *it;
    }*/

}