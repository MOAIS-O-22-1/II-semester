//������� �����, �����-�-22/1, ������� 8;
#include <iostream>
#include <math.h>
using namespace std;

long double* AB(long int* P2, float* P3) // �������������� ���������
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

	long double* P1 = AB(P2, P3);  // ������� ������������ ��������� �� ��� �1

	cout << "�������� ��������� P1: " << P1 << endl << "��������, �� ������� �� ���������: " << *P1 << endl;
	delete P1, P2, P3;
}