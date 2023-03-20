#include <iostream>
#include <ctime>
#include <cstdlib>
#define A -100
#define B 100



using namespace std;

void PrintArray(int*& arr, const size_t& n)
{
	for (size_t i = 0; i < n; i++)
	{
		cout << *(arr + i) << " ";
	}
	cout << endl;
}


int* add_back(int*& arr, size_t& n, size_t& k)
{

	int* new_arr = new int[n + k];
	for (size_t i = 0; i < n + k; i++)
	{
		if (i < n)
		{
			*(new_arr + i) = *(arr + i);
		}
		else
		{
			*(new_arr + i) = A + rand() % (B - A + 1);
		}
	}
	delete[] arr;
	return new_arr;

	

}

int* init_Array(size_t& n)
{
	srand(time(NULL));
	int* arr = new int[n];
	for (size_t i = 0; i < n; i++)
	{
		*(arr + i) = A + rand() % (B - A + 1);
	}
	return arr;
	
	

}

void freeing_up_memory(int*& arr)
{
	delete[] arr;
}



int main()
{
	setlocale(LC_ALL, "Rus");
	size_t n, k;
	int* arr;
	cout << "Введите размер массива: ";
	cin >> n;
	cout << "Введите количество элементов для добавления в конец массива: ";
	cin >> k;
	arr = init_Array(n);
	cout << "Исходный массив: ";
	PrintArray(arr, n);
	arr = add_back(arr, n, k);
	cout << "Измененный массив: ";
	PrintArray(arr, n + k);
	freeing_up_memory(arr);


}