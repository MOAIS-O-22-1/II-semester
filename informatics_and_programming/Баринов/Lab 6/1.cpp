// Вариант 3

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double fun(double x);

int main() {
    
    setlocale(LC_ALL, "ru");

    double count = 0, sum = 0;
    
    cout << left << setw(10) << "x" << right << setw(10) << "f(x)" << endl;
    for (double x = 1; x < 2.05; x += 0.05){
        cout << left << setw(10) << x << right << setw(10) << fun(x) << endl;
        sum += fun(x);
        count++;
    }

    cout << "Среднее значение функции: " << sum / count << endl;

    system("pause");
    return 0;

}

double fun(double x) {

    if (1 <= x < 1.2) return (2.8 * x * x - 0.3 * x + 4);
    else if (1.2 <= x < 1.6) return (2.8 / x + sqrt(x * x + 1));
    else if (x >= 1.6) return ((2.8 - 0.3 * x) / sqrt(x * x + 1));
    else return 0;

}