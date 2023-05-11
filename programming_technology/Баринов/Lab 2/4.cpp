#include <iostream>
#include <queue>
#include <string>

using namespace std;

priority_queue <int> main_queue;

void condition();
void add(int n);
void extract();
void clear();
void exit();

int main() {

    condition();

    return 0;

}

void condition() {

    string s;
    while (cin >> s) {
        if (s == "CLEAR") {
            clear();
        }
        else if (s == "EXTRACT") {
            extract();
        }
        else if (s == "ADD") {
            int num;
            cin >> num;
            add(num);
        }
    }

}

void add(int n) {
    main_queue.push(n);
}

void extract() {
    if (main_queue.size() == 0) {
        cout << "CANNOT" << endl;
        return;
    }
    cout << main_queue.top() << endl;
    main_queue.pop();
}

void clear() {
    while (!main_queue.empty())
        main_queue.pop();
}

void exit() {
}