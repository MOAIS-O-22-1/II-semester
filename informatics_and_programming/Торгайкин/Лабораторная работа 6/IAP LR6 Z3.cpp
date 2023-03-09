#include <iostream>
#include <cmath>
#define Pi  3.14159265358979323846 ;

using namespace std;


void largeAngle(double &x1, double &y1, double &x2, double &y2, double &x3, double &y3)
{
	double Ang1, Ang2, Ang3;

	Ang1 = acos(((x2 - x1) * (x3 - x1) + (y2 - y1) * (y3 - y1)) / (sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)) * sqrt(pow(x3 - x1, 2) + pow(y3 - y1, 2)))) * 180/Pi;
	Ang2 = acos(((x1 - x2) * (x3 - x2) + (y1 - y2) * (y3 - y2)) / (sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2)) * sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2)))) * 180/Pi;
	Ang3 = acos(((x1 - x3) * (x2 - x3) + (y1 - y3) * (y2 - y3)) / (sqrt(pow(x1 - x3, 2) + pow(y1 - y3, 2)) * sqrt(pow(x2 - x3, 2) + pow(y2 - y3, 2)))) * 180/Pi;
	cout << "Самый большой угол треугольника: " <<  max(max(Ang1, Ang2), Ang3) << endl;
}



int main()
{
	setlocale(LC_ALL, "Rus");
	double x1, x2, x3, y1, y2, y3;
	cout << "Введите x1 и y1: ";
	cin >> x1 >> y1;
	cout << "Введите x2 и y2: ";
	cin >> x2 >> y2;
	cout << "Введите x3 и y3: ";
	cin >> x3 >> y3;
	if (x1 == x2 && y1 == y2 || x1 == x3 && y1 == y3 || x2 == x3 && y2 == y3) { cout << "Введены неверные координаты вершин" << endl; return 1; }


	largeAngle(x1, y1, x2, y2, x3, y3);
	
}