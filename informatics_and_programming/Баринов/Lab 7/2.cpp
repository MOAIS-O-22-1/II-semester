#include <iostream>
#include <random>
#include <malloc.h>

#define A -50
#define B 50

using namespace std;

int* create_an_array(const size_t& size);
int* add_to_array(int*& array, size_t& size, const int& number, const size_t& count = 1);
int* remove_from_array(int*& array, size_t& size, const int& key);
void print_array(int*& array, size_t& size);

int main() {

    size_t size;
    int key;

    cout << "Enter the length of the array: ";
    cin >> size;

    int* array_of_num = create_an_array(size);

    cout << "Created array:" << endl;
    print_array(array_of_num, size);

    cout << "Enter key: ";
    cin >> key;
    array_of_num = remove_from_array(array_of_num, size, key);
    cout << "Modified array:" << endl;
    print_array(array_of_num, size);

    free(array_of_num);

    return 0;

}

int* create_an_array(const size_t& size) {

    int* array;
    try {
        array = (int*)realloc(NULL, sizeof(int) * size);
        for (int* ptr{ array }; ptr < array + size; ptr++) {
            *ptr = rand() % (B - A + 1) + A;
        }
    }

    catch (const bad_alloc& e) {
        cout << "ERROR!!!(Memory not allocated): " << e.what() << endl;
        terminate();
    }

    return array;
}

int* add_to_array(int*& array, size_t& size, const int& number, const size_t& count) {

    try {
        size += count;
        array = (int*)realloc(array, sizeof(int) * size);
        for (int* ptr{ array + size - 1 }; ptr > array + size - 1 - count; ptr--) {
            *ptr = number;
        }
    }

    catch (const bad_alloc& e) {
        cout << "ERROR!!!(Memory not allocated): " << e.what() << endl;
        terminate();
    }

    return array;

}

int* remove_from_array(int*& array, size_t& size, const int& key) {

    try {
        for (int* ptr{ array }; ptr < array + size; ptr++) {
            if (*ptr == key) {
                for (int* ptr_tmp{ ptr }; ptr_tmp < array + size - 1; ptr_tmp++) {
                    *ptr_tmp = *(ptr_tmp + 1);
                }
                size--;
            }
        }
        array = (int*)realloc(array, sizeof(int) * size);
    }

    catch (const bad_alloc& e) {
        cout << "ERROR!!!(Memory not allocated): " << e.what() << endl;
        terminate();
    }

    return array;

}

void print_array(int*& array, size_t& size) {

    for (int* ptr{ array }; ptr < array + size; ptr++) {
        cout << *ptr << " ";
    }
    cout << endl;

}