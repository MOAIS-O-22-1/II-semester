#include <iostream>
#include <cmath>

using namespace std;


signed int* function(short int*& P2, char*& P3)
{

	signed int* AB = new signed int;
	*AB = pow((sin(*P2) / tan(*P3)), *P3);
	return AB;
}





int main()
{
	setlocale(LC_ALL, "Rus");

	signed int* P1;
	short int* P2 = new short int;
	char* P3 = new char;

	cout << "Введите P2: ";
	cin >> *P2;
	cout << "Введите P3: ";
	cin >> *P3;
	P1 = function(P2, P3);
	cout << *P2 << endl;
	cout << P2 << endl;


	delete P1;
	delete P2;
	delete P3;
	
}