//Илюнкин Денис, МОАИС-О-22/1, вариант 8;
#include <iostream>
#include <math.h>
using namespace std;

long double* AB(long int* P2, float* P3) // арифметическое выражение
{
	long double* P1 = new long double;
	*P1 = pow((1+(++*P2)) / *P3, *P2);
	return P1;
}

int main()
{
	setlocale(LC_ALL, "rus");
	long int* P2 = new long int; //auto* P2 ..
	float* P3 = new float;

	cout << "P2: ";
	cin >> *P2;
	cout << "P3: ";
	cin >> *P3;

	long double* P1 = AB(P2, P3);  // функция возвращающая указатель на тип Р1

	cout << "Значение указателя P1: " << P1 << endl << "Значение, на которое он ссылается: " << *P1 << endl;
	delete P1, P2, P3;
}