#include <iostream>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <iomanip>

using namespace std;
void condition(const size_t& n, map <string, string>& reg, set <string>& users);
void regist(map <string, string>& reg);
void login(map <string, string>& reg, set <string>& users);
void logout(map <string, string>& reg, set <string>& users);


int main() {

    size_t n;
    map <string, string> reg;
    set <string> users;

    cin >> n;

    condition(n, reg, users);

    return 0;
}

void condition(const size_t& n, map <string, string>& reg, set <string>& users) {

    string command = "";

    for (size_t i = 0; i < n; i++) {
        cin >> command;
        if (command == "register") regist(reg);
        else if (command == "login") login(reg, users);
        else if (command == "logout") logout(reg, users);
    }
    
}

void regist(map <string, string>& reg) {

    string username, password;
    int len = reg.size();
    cin >> username >> password;
    reg[username] = password;

    if (reg.size() == len) cout << "fail: user already exists" << endl;
    else cout << "success: new user added" << endl;

}

void login(map <string, string>& reg, set <string>& users) {

    string username, password;
    cin >> username >> password;
    auto it = reg.find(username);
    if (it == reg.end()) 
        cout << "fail: no such user" << endl;
    else if ((*it).first == username && (*it).second != password) 
        cout << "fail: incorrect password" << endl;
    else if ((*it).first == username && (*it).second == password  && users.find(username) != users.end())
        cout << "fail: already logged in" << endl;
    else if ((*it).first == username && (*it).second == password && users.find(username) == users.end()) {
        users.insert(username);
        cout << "success: user logged in" << endl;
    }

}

void logout(map <string, string>& reg, set <string>& users) {

    string username;
    cin >> username;
    auto it = users.find(username);
    if (it == users.end() && reg.find(username) == reg.end())
        cout << "fail: no such user" << endl;
    else if (it == users.end() && reg.find(username) != reg.end())
        cout << "fail: already logged out" << endl;
    else if (it != users.end() && reg.find(username) != reg.end()) {
        users.erase(username);
        cout << "success: user logged out" << endl;
    }

}