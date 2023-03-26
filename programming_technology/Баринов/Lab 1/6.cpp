#include <iostream>
#include <string>
#include <map>
#include <set>

using namespace std;

map< set<string>, int > print_and_return_map(const int& q);

int main() {

    int q;
    cin >> q;

    map< set<string>, int > buses;

    buses = print_and_return_map(q);

    return 0;

}

map< set<string>, int > print_and_return_map(const int& q) {

    map< set<string>, int > buses;

    for (size_t i = 0; i < q; i++) {

        set <string> stops;
        int stop_count;
        cin >> stop_count;

        for (int j = 0; j < stop_count; j++) {
            string stop;
            cin >> stop;
            stops.insert(stop);
        }

        if (buses.count(stops)) {
            cout << "Already exists for " << buses[stops] << endl;
        }

        else {
            buses[stops] = buses.size() + 1;
            cout << "New bus " << buses[stops] << endl;
        }

    }

    return buses;

}