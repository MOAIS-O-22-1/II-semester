//Ilyunkin Denis, MOAIS-O-22/1, var 8, inf and prog
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

void calculator(float x1, float x2, float h)
{
	float x = x1, sum_y = 0, cnt = 0;
	while (x < x2)
	{
		if (x > 3.5)
		{
			float y = 0.2 * sin(x) * log10(x);
			cout << fixed << setw(11) << x << setw(11) << y << endl;
			sum_y += y;
			cnt++;
		}
		if (x <= 3.5)
		{
			float y = ((cos(x) * cos(x)) / 0.2);
			cout << fixed << setw(11) << x << setw(11) << y << endl;
			sum_y += y;
			cnt++;
		}
		x += h;
	}
	cout << "   ------------------- " << endl;
	cout << "Среднее значение функции: " << sum_y / cnt << endl;
}

int main() 
{
	setlocale(LC_ALL, "rus");
	float x1 = 2, x2 = 5, h = 0.25;
	cout << "       x       y(x)  " << endl;
	cout << "   ------------------- " << endl;
	calculator(x1, x2, h);
}