#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

void print_vec(vector<string>& vec);
void print_vec(set<string>& vec);

void condition(map<string, set<string>>& bus_information, int& q);
void new_bus(map<string, set<string>>& bus_information, string& bus, string& stop);
void buses_for_stop(const string& stop, map<string, set<string>>& bus_information);
void stops_for_bus(const string& bus, map<string, set<string>>& bus_information);
void all_buses(map<string, set<string>>& bus_information);

int main() {

    int q;
    cin >> q;

    map<string, set<string>> bus_information;

    condition(bus_information, q);

    return 0;
}

void print_vec(vector<string>& vec) {

    for (auto elem : vec) {
        cout << elem << " ";
    }

}

void print_vec(set<string>& vec) {

    for (auto elem : vec) {
        cout << elem << " ";
    }

}

void condition(map<string, set<string>>& bus_information, int& q) {

    for (size_t i = 0; i < q; i++) {
        string command, bus, stop;
        cin >> command;
        if (command == "NEW_BUS") {
            new_bus(bus_information, bus, stop);
        }
        else if (command == "BUSES_FOR_STOP") {
            cin >> stop;
            buses_for_stop(stop, bus_information);
        }
        else if (command == "STOPS_FOR_BUS") {
            cin >> bus;
            stops_for_bus(bus, bus_information);
        }
        else if (command == "ALL_BUSES") {
            all_buses(bus_information);
        }
        else cout << "Invalid command!!!" << endl;
    }

}

void new_bus(map<string, set<string>>& bus_information, string& bus, string& stop) {

    int stop_count;
    cin >> bus >> stop_count;
    for (size_t i = 0; i < stop_count; i++) {
        cin >> stop;
        bus_information[bus].insert(stop);
    }

}

void buses_for_stop(const string& stop, map<string, set<string>>& bus_information) {

    vector<string> vec_all_buses;
    for (auto bus : bus_information) {
        for (auto this_bus_stop : bus.second) {
            if (this_bus_stop == stop) {
                vec_all_buses.push_back(bus.first);
            }
        }
    }
    if (vec_all_buses.size() != 0) {
        print_vec(vec_all_buses);
    }

    else if (vec_all_buses.size() == 0) cout << "No stop" << endl;

}

void stops_for_bus(const string& bus, map<string, set<string>>& bus_information) {

    int count = 0;
    for (auto bus_i : bus_information) {
        if (bus_i.first == bus) {
            for (auto stop_i : bus_i.second) {
                cout << "Stop " << stop_i << ": ";
                vector<string> vec_stops_for_bus;
                for (auto bus_r : bus_information) {
                    for (auto stop_r : bus_r.second) {
                        if (stop_r == stop_i && bus_r.first != bus) {
                            vec_stops_for_bus.push_back(bus_r.first);
                        }
                    }
                }
                if (vec_stops_for_bus.size() == 0) cout << " no interchange";
                else if (vec_stops_for_bus.size() > 0) {
                    print_vec(vec_stops_for_bus);
                }
                cout << endl;
            }
            count++;
        }
    }

    if (count == 0) cout << "No bus" << endl;

}

void all_buses(map<string, set<string>>& bus_information) {

    if (bus_information.size() == 0) cout << "No buses" << endl;
    else {
        for (auto bus : bus_information) {
            cout << "Bus " << bus.first << ": ";
            print_vec(bus.second);
            cout << endl;
        }
    }

}