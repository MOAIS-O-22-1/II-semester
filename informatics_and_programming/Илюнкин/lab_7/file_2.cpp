//Илюнкин Денис, МОАИС-О-22/1, вариант 8;
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int* memory_f(int size)
{
	int* ptr = new int[size];
	return ptr;
}

int* rand_f(int size, int* ptr)
{
	srand(time(NULL));
	for (int i = 0; i < size; i++)
	{
		*(ptr + i) = rand();
	}
	return ptr;
}

int* del_f(int* new_ptr, int* ptr, int size)
{
	for (int i = 0; i < (size / 2 + 1); i++, ptr = ptr + 2)
	{
		*(new_ptr + i) = *ptr;
	}
	return new_ptr;
}

int main()
{
	int size;
	cin >> size;

	int* ptr;
	int* new_ptr;
	ptr = memory_f(size);
	new_ptr = memory_f(size);
	rand_f(size, ptr);

	del_f(new_ptr, ptr, size);

	for (int i = 0; i < size; i++) { cout << *(ptr + i) << " "; }
	cout << endl;
	for (int i = 0; i < (size / 2 + (size % 2)); i++) { cout << *(new_ptr + i) << " "; }
	delete ptr;
	delete new_ptr;
}