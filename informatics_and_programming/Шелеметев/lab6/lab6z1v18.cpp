#include <iostream>
#include <cmath>

using namespace std;

float func_v18(float x)
{
    x = round(x * 10) / 10;

    float y = 0;
    if (x < 2) {
        y = 2 * pow(log(x), 2);
    }
    else if (x >= 2 && x <= 3) {
        y = (pow(x + 1, 3.0)) - 2.0;
    }
    else if (x > 3) {
        y = 3.0 / tan(x);
    }

    return y;
}

int main()
{
    setlocale(LC_ALL, "Russian");

    float x_start = 1;
    float x_end = 3.4;
    float h = 0.2;

    float sum = 0.0;
    int count = 0;

    // вычисляем значения функции на интервале и выводим результаты
    for (float x = x_start; x <= x_end; x += h) {
        float y = func_v18(x);
        cout << "x = " << x << ", y = " << y << endl;

        sum += y;
        count++;
    }

    // вычисляем и выводим среднее значение функции на интервале
    float avg = sum / count;
    cout << "Среднее значение функции на интервале: " << avg << endl;

    return 0;
}