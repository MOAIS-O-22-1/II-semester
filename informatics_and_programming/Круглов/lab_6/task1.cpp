#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

void z1(float x1, float x2, float h){
    float x = x1, sum1 = 0, cnt = 0;
    while (x < x2){
        if (x > 1){
            float y = log10(x + 1);
            cout << fixed << setw(11) << x << setw(11) << y << endl;
            sum1 += y;
            cnt++;
    }
        if (x <= 1){
            float y = pow(sin(sqrt(x)), 2);
            cout << fixed << setw(11) << x << setw(11) << y << endl;
            sum1 += y;
            cnt++;
    }
        x += h;
    }
    cout << "summa " << sum1 / cnt << endl;
}

int main()
{
    float x1 = 0.5, x2 = 2, h = 0.1;
    z1(x1, x2, h);
}
