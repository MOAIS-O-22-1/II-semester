//Ilyunkin Denis, MOAIS-O-22/1, var 8
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double square(const double &x1, const double &y1, const double &x2, const double &y2, const double &x3, const double &y3) //корды трёх точек
{
	double a, b, c, p, S; //стороны треугольника
	a = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
	b = sqrt(pow((x3 - x2), 2) + pow((y3 - y2), 2));
	c = sqrt(pow((x1 - x3), 2) + pow((y1 - y3), 2));
	p = (a + b + c) / 2;
	S = sqrt(p * (p - a) * (p - b) * (p - c));
	return S;
}

int main()
{
	double x1, y1, x2, y2, x3, y3, xr, yr;
	cout << "1st point: ";
	cin >> x1 >> y1;
	cout << "2nd point: ";
	cin >> x2 >> y2;
	cout << "3rd point: ";
	cin >> x3 >> y3;
	cout << "Random point: ";
	cin >> xr >> yr;
	cout << square(x1, y1, x2, y2, x3, y3) << endl;
	cout << square(xr, yr, x2, y2, x3, y3) << endl;
	cout << square(x1, y1, xr, yr, x3, y3) << endl;
	cout << square(x1, y1, x2, y2, xr, yr) << endl;
}