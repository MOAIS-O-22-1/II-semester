#include <iostream>
#include <random>
#include <malloc.h>

#define A -50
#define B 50

using namespace std;

int* create_an_array(const size_t& size);
void print_array(int*& array, size_t& size);
int* max_negative(int*& array, const size_t& size);

int main() {
    
    size_t size;

    cout << "Enter the length of the array: ";
    cin >> size;

    int* array_of_num = create_an_array(size);

    cout << "Created array:" << endl;
    print_array(array_of_num, size);

    array_of_num = max_negative(array_of_num, size);
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

void print_array(int*& array, size_t& size) {

    for (int* ptr{ array }; ptr < array + size; ptr++) {
        cout << *ptr << " ";
    }
    cout << endl;

}

int* max_negative(int*& array, const size_t& size) {

    int max_elem = 0;
    for (int* ptr{ array }; ptr < array + size; ptr++) {
        if (*ptr < 0 && (max_elem == 0 || *ptr > max_elem)) max_elem = *ptr;
    }

    if (max_elem == 0) {
        cout << "No negative numbers!" << endl;
        return array;
    }
    else {
        for (int* ptr{ array }; ptr < array + size; ptr++) {
            if (*ptr % 2 == 0) *ptr = max_elem;
        }
        return array;
    }

}