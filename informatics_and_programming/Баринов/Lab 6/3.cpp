// Вариант 3

#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>

#define PI 3.141592653589793

using namespace std;

double getTriangleAngle(double x1, double y1, double x2, double y2, double x3, double y3);

int main() {
    
    setlocale(LC_ALL, "ru");

    double x1, y1, x2, y2, x3, y3;
    cout << "Введите x1, y1, x2, y2, x3, y3: " << endl;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    cout << "Наибольший угол в градусах = " << getTriangleAngle(x1, y1, x2, y2, x3, y3) << endl;
    
    system("pause");
    return 0;

}

double getTriangleAngle(double x1, double y1, double x2, double y2, double x3, double y3) {

    double A = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    double B = sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2));
    double C = sqrt(pow(x3 - x1, 2) + pow(y3 - y1, 2));
    double angA = acosl((B * B + C * C - A * A) / (2 * B * C)) * (180 / PI);
    double angB = acosl((A * A + C * C - B * B) / (2 * A * C)) * (180 / PI);
    double angC = acosl((B * B + A * A - C * C) / (2 * B * A)) * (180 / PI);
    
    return max(max(angA, angB), angC);
        
}

// 0 0 2 0 2 3
// 0 0 2 1 3 3