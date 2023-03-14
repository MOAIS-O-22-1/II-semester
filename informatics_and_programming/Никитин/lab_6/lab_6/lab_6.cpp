#include <iostream>
#include "math.h"
#include <string>
#include <vector>
#include <sstream>

using namespace std;

double Scet(double x) {
    if (x < 2.8) {
        return(exp(x)+cos(x));
    }
    else if (x >= 2.8 && x < 6) {
        return(1 / (1 + x));
    }
    else {
        return(exp(x) + sin(x));
    }
}
string zad2(string text)
{
    string final="";
    string word;//Будет содержать текущее слово из текста
    stringstream ss(text);//Инициализация строкового потока
    vector <string> array;//Вектор, каждый элемент которого слово из текста
    while (ss >> word)
        array.push_back(word);
    for (int i = 1; i < array.size(); i += 1) {
        array.erase(array.begin() + i);
    }
    for (int i = 0; i < array.size(); i++) {
        final =final + array[i] + " ";
    }
    return final;
}
string zad3(int x1,int x2,int x3,int x4,int y1,int y2,int y3,int y4) {
    setlocale(LC_ALL, "Russian");
    double a, b, c, d;
    a = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    b = sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2));
    c = sqrt(pow(x4 - x3, 2) + pow(y4 - y3, 2));
    d = sqrt(pow(x1 - x4, 2) + pow(y1 - y4, 2));
    if (a == b == c == d) {
        return "Квадрат";
    }
    else if (a == c && a != b && b == d) {
        return "Прямоугольник";
    }
    else if (b == d && a != c && a != b && c != b) {
        return "Равнобедреная трапеция";
    }
    else {
        return "Произвольный прямоугольник";
    }
}

int main(){
    setlocale(LC_ALL, "Russian");
    int p=0;
    cin >> p;
    switch (p)
    {
    case 1:
    {
        cout << "x\t" << "y(x)\n";
        for (double x = 0; x <= 7; x += 0.5) {
            cout << x << "\t" << Scet(x) << "\n";
        }
    }
    case 2:
    {
        cin.ignore();
        string text;
        getline(cin, text);
        cout << zad2(text);
    }
    case 3 :
        int x1, x2, x3, x4, y1, y2, y3, y4;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
        cout << zad3(x1, x2, x3, x4, y1, y2, y3, y4);
    }
}
