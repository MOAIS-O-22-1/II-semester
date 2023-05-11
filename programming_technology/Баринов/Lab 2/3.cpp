#include <iostream>
#include <queue>
#include <string>

using namespace std;

queue <int> main_queue;

void condition();
void push(int n);
void pop();
void front();
void size();
void clear();
void exit();

int main() {

    condition();

    return 0;

}

void condition() {

    string s;
    cin >> s;

    while (s != "exit") {
        if (s == "clear") {
            clear();
        }
        else if (s == "pop") {
            pop();
        }
        else if (s == "front") {
            front();
        }
        else if (s == "size") {
            size();
        }
        else if (s == "push") {
            int num;
            cin >> num;
            push(num);
        }
        cin >> s;
    }
    exit();

}

void push(int n) {
    cout << "ok" << endl;
    main_queue.push(n);
}

void pop() {
    if (main_queue.size() == 0) {
        cout << "error" << endl;
        return;
    }
    cout << main_queue.back() << endl;
    main_queue.pop();
}

void front() {
    if (main_queue.size() == 0) {
        cout << "error" << endl;
        return;
    }
    cout << main_queue.front() << endl;
}

void size() {
    cout << main_queue.size() << endl;
}

void clear() {
    cout << "ok" << endl;
    while (!main_queue.empty())
        main_queue.pop();
}

void exit() {
    cout << "bye" << endl;
}