// Илюнкин Денис, МОАИС-О-22/1, лаб 9, вариант 8
#include <iostream>
#include <math.h>
using namespace std;


void nat_log(const float &num)
{
	if (num < 0)
	{
		throw("Введено число, меньшее нуля.");
	}
	if (num == 0)
	{
		throw("Введено число, равное нулю.");
	}
	cout << "Успех: Вычисление прошло успешно." << endl << "Результат: " << log(num) << endl;
}


int main() {
	setlocale(LC_ALL, "ru");
	int num;
	cout << "---- Вычисление натурального логарифма от числа num ----" << endl;


	try
	{
		cout << "Введите число: ";
		cin >> num;
		nat_log(num);
	}


	catch (const char *ex)
	{
		cout << "Ошибка: " << ex << endl;
		cout << "Результат: Не определён." << endl;
	}
}