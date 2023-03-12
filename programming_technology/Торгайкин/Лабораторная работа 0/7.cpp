#include <iostream>
#include <random>
#include <vector>
#include <ctime>


using namespace std;

bool Alternation(int number)
{
	number = abs(number);
	if (number / 10 == 0)
	{
		return false;
	}
	int num1 = number % 10, num2;
	number = number / 10;
	while (number)
	{
		num2 = number % 10;
		if (num1 % 2 == 0 && num2 % 2 == 0 || num1 % 2 != 0 && num2 % 2 != 0)
		{
			return false;
		}
		num1 = num2;
		number = number / 10;
	}
	return true;
}


void Function(const vector <int>& numbers)
{
	int sum = 0;
	for (size_t i = 0; i < numbers.size() - 1; i++)
	{
		if (Alternation(numbers[i]) == true)
		{
			sum += numbers[i];
		}
	}
	cout << "Сумма элементов с чередующими четными и нечетными цифрами: " << sum << endl;
}




int main()
{
	setlocale(LC_ALL, "Rus");
	int number;
	vector <int> numbers;
	mt19937 random_value(time(NULL));
	uniform_int_distribution <size_t> interval{ 5, 30 };
	uniform_int_distribution <int> range{ -3200, 3200 };

	
	for (size_t i = 0; i < interval(random_value); i++)
	{
		number = range(random_value);
		if (number != 0)
		{
			numbers.push_back(number);
			cout << number << " ";
		}

	}
	numbers.push_back(0);
	cout << 0 << endl;
	Function(numbers);


}