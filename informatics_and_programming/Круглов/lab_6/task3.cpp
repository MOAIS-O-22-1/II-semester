#include <iostream>

using namespace std;

int z3r(int x1, int x2){
    if (x2 == 0){
        return x1;
    }
    return z3r(x2, x1 % x2);
}

void z3(int a, int b){
    while (a != 0 & b != 0){
        if (a > b){
            a = a % b;
        }
        else{
            b = b % a;
        }
    }
    cout << a + b << endl;
}

int nok(int a, int b){
    return a * b / z3r(a, b);
}

int main()
{
    int x1, x2;
    cin >> x1 >> x2;
    cout << z3r(x1, x2) << endl;
    z3(x1, x2);
    cout << nok(x1, x2) << endl;
}
