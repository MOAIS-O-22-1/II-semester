#include <iostream>

using namespace std;


class Error
{
    public:
    string stroka;
    Error(string str)
     {
        stroka = str;
     }
};

int main()
{
    setlocale(LC_ALL, "");
    int age;
    try
    {
        cout << "Введите возраст: "; cin >> age;
        if (age < 0) 
        {
            throw Error("Возраст не может быть отрицательным!"); 
        }

    }
    catch (Error x)
    {
        cout << x.stroka;
    }
}