#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

// Функция для вычисления площади треугольника по координатам вершин
double area(double x1, double y1, double x2, double y2, double x3, double y3) {
    return 0.5 * abs((x1 - x3) * (y2 - y3) - (x2 - x3) * (y1 - y3));
}

// Функция для вычисления расстояния от точки до отрезка по координатам точек на отрезке и точки вне отрезка
double distance(double x1, double y1, double x2, double y2, double x, double y) {
    double dx = x2 - x1;
    double dy = y2 - y1;
    double t = ((x - x1) * dx + (y - y1) * dy) / (dx * dx + dy * dy);
    if (t < 0) {
        t = 0;
    }
    else if (t > 1) {
        t = 1;
    }
    double closestX = x1 + t * dx;
    double closestY = y1 + t * dy;
    double distX = x - closestX;
    double distY = y - closestY;
    return sqrt(distX * distX + distY * distY);
}

// Функция для нахождения расстояния от точки до ближайшей стороны треугольника
double distanceToSide(double x1, double y1, double x2, double y2, double x3, double y3, double x, double y) {
    double d1 = distance(x1, y1, x2, y2, x, y);
    double d2 = distance(x2, y2, x3, y3, x, y);
    double d3 = distance(x3, y3, x1, y1, x, y);
    return min({ d1, d2, d3 });
}

int main() {
    // Считываем координаты вершин треугольника и координаты точки
    double x1, y1, x2, y2, x3, y3, x, y;
    cout << "input x , y: ";
    cin >> x >> y;
    cout << "input x1, y1, x2, y2, x3, y3: ";
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    double d = distanceToSide(x1, y1, x2, y2, x3, y3, x, y);
    cout << "the nearest distance to side = " << d;

}