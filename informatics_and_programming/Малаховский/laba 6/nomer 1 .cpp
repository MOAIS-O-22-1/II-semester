#include <iostream>
#include <iostream>
#include <cmath>

using namespace std;

double func(double x) {
	if (x <= 0.5) return (pow(log10(x), 3) + pow(x, 2)) / (sqrt(x + 2.2));
	if (x >= 0.5) return sqrt(x + 2.2) + 1 / x;
}
int main() {
	setlocale(LC_ALL, "Russian");
	int count = 0;
	double y, sum;
	printf("|  x  |   y   |\n");
	for (double x = 0.2; x <= 2; x += 0.2) {
		y = func(x);
		sum = +y;
		count += 1;
		printf("|%5.1f|%7.2f|\n", x, y);
	}

	cout << "среднее значение функции = " << (sum / count) << endl;

	return 0;
}