#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;


double calculate(double num)
{
	if (sin((num * num + 1) / 2) > 0) { return sin((num * num + 1) / 2); }
	else if (sin((num * num + 1) / 2) < 0) { return cos(num + 0.5); }
	
}


void function(double beg, double &end, double &h)
{
	double sum = 0;
	int counter = 0;
	cout << "\t+-------+---------------+" << endl;
	cout << "\t|" << setw(3) << "X" << "\t| " << "Y\t\t" << "|" << endl;
	cout << "\t+-------+---------------+" << endl;
	for (; beg <= end; beg += h)
	{

		cout << "\t|  " << beg << "\t|  " << calculate(beg) << "\t|" << endl;
		cout << "\t+-------+---------------+" << endl;
		counter += 1;
		sum += calculate(beg);
	}
	cout << "Среднее значение функции: " << sum / counter << endl;
}

int main()
{
	setlocale(LC_ALL, "Rus");
	double beg = 1, end = 10, h = 0.5;

	function(beg, end, h);
}