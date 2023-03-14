#include <iostream>
#include <malloc.h>
#include <cmath>

using namespace std;

double* fun(int*& p2, long*& p3);
void memory_allocation(double*& p1, int*& p2, long*& p3);

int main() {

    double* p1;
    int* p2;
    long* p3;

    memory_allocation(p1, p2, p3);

    cout << "Enter p2, p3: " << endl;
    cin >> *p2 >> *p3;

    p1 = fun(p2, p3);

    cout << "Variable address: " << p2 << endl 
        << "Pointer address: " << &p2 << endl
        << "Value by address: " << *p2 << endl;

    cout << "F = " << *p1 << endl;

    delete p1;
    delete p2;
    delete p3;

    return 0;

}

void memory_allocation(double*& p1, int*& p2, long*& p3) {

    try {
        p1 = new double;
        p2 = new int;
        p3 = new long;
    }

    catch (const bad_alloc& e) {
        cout << "ERROR!!!(Memory not allocated): " << e.what() << endl;
        terminate();
    }

}

double* fun(int*& p2, long*& p3) {

    double* ab = new double;
    *ab = tan(pow(pow(*p3, 2), (*p2 / 3)));

    return ab;

    delete ab;
}