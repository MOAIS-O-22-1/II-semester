#include <iostream>
#include <ctime>
#include <cstdlib>
#define A -100
#define B 100


using namespace std;


int main()
{
	setlocale(LC_ALL, "Rus");
	int sum;
	size_t n;
	cout << "Введите количество элементов массива: ";
	cin >> n;
	int* arr = new int[n];
	srand(time(NULL));
	

	for (size_t i = 0; i < n; i++)
	{
		*(arr + i) = A + rand() % (B - A + 1);
	}
	cout << "Исходный массив: ";
	for (size_t i = 0; i < n; i++)
	{
		cout << *(arr + i) << " ";
	}
	cout << endl;

	sum = *(arr) + *(arr + 1);
	for (size_t i = 0; i < n - 1; i++)
	{
		if (*(arr + i) + *(arr + i + 1) > sum)
		{
			sum = *(arr + i) + *(arr + i + 1);
		}
	}

	for (size_t i = 0; i < n; i++)
	{
		if (*(arr + i) > 0)
		{
			*(arr + i) = sum;
		}
	}

	cout << "Преобразованный массив: ";
	for (size_t i = 0; i < n; i++)
	{
		cout << *(arr + i) << " ";
	}
	cout << endl;

	delete[] arr;
}