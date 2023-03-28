//Илюнкин Денис, МОАИС-О-22/1, вариант 8;
#include <iostream>
//#include <vector> // без индексации --> указатель
#include <stdlib.h>
#include <ctime>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));
	int size, cnt = 0;
	cin >> size;

	int* ptr = new int[size]; // Указатель и динамическое выделение памяти


	for (int i = 0; i < size; i++)
	{
		*(ptr + i) = (-50 + rand() % 100);
		//cout << ptr << endl;
	}


	for (int i = 0; i < (size - 1); i++) 
	{
		if (((*(ptr + i + 1) >= 0) && (*(ptr + i) < 0)) || ((*(ptr + i + 1) < 0) && (*(ptr + i) >= 0)))
		{
			cnt += 1;
		}
	}

	cout << "\nМассив: " << endl;
	for (int i = 0; i < size; i++)
	{
		cout << *(ptr + i) << endl;
	}

	cout << "\nКоличество пар соседних элементов с разными знаками: " << cnt << endl;
	delete ptr;
}