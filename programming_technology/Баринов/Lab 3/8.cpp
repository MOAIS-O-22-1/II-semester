#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <iomanip>

using namespace std;

struct Date {
    int day;
    int month;
    int year;
};

bool operator < (const Date& f, const Date& s) {     // ���������� ��������� < 
    if (f.year != s.year) return f.year < s.year;
    else {
        if (f.month != s.month) return f.month < s.month;
        else return f.day < s.day;
    }
}

void condition(map <Date, double>& profit);
void �omputeIncome(map <Date, double>& profit);
void earn(map <Date, double>& profit);
void calculate(pair <Date, Date>& date_range, double& value, map <Date, double>& profit);
pair <Date, Date> enter_date();

int main() {

    map <Date, double> profit;

    condition(profit);

    return 0;
}

// Earn 2000-01-02 2000-01-06 20
// ComputeIncome 2000-01-01 2001-01-01

void condition(map <Date, double>& profit) {

    int q;
    cin >> q;

    for (size_t i = 0; i < q; i++) {
        string request;
        cin >> request;

        if (request == "ComputeIncome") {
            �omputeIncome(profit);
        }

        else if (request == "Earn") {
            earn(profit);
        }

        else i--;
    }

}

void �omputeIncome(map <Date, double>& profit) {

    double count_money = 0;                      // ������� ��
    pair <Date, Date> date_range = enter_date();   // ��������� ����

    profit[date_range.first] += 0;
    auto it_first = profit.find(date_range.first);
    profit[date_range.second] += 0;
    auto it_second = profit.find(date_range.second);

    for (auto it = it_first; it != it_second; it++) { // ������� ��
        count_money += (*it).second;
    }
    count_money += (*it_second).second;   // ������� ��������� ����

    cout.precision(5);
    //cout.setf(ios::fixed);
    cout << count_money << endl; 

}

void earn(map <Date, double>& profit) {

    double value;                        // �� �� ���� ����������
    pair <Date, Date> date_range = enter_date();
    
    cin >> value;
    calculate(date_range, value, profit);      // ������������� �� �� ���� �� ���������� � ���������� �������

}

void calculate(pair <Date, Date>& date_range, double& value, map <Date, double>& profit) {
    
    vector <int> months = { 31,28,31,30,31,30,31,31,30,31,30,31 };     // ��� � �������
    auto feb = months.begin() + 1;                // ��������� �� �������
    int cnt = 1;

    profit[date_range.first] += 0;
    auto it_first = profit.find(date_range.first);

    while (date_range.first.day != date_range.second.day ||    // �������� � ������� ���������� ���� ����� ������
        date_range.first.month != date_range.second.month ||
        date_range.first.year != date_range.second.year) {

        profit[date_range.first] += 0;

        if (date_range.first.year % 4 == 0) *feb = 29; // ���� ����������
        if(date_range.first.year % 4 != 0 && *feb == 29) *feb = 28; // ������� �� �����������

        cnt++;

        if (date_range.first.day != *(months.begin() + date_range.first.month - 1)) date_range.first.day++;
        else {                                 // ���� ��������� ���� � ������
            date_range.first.day = 1;
            date_range.first.month++;
            if (date_range.first.month == 13) { // ���� ��������� ���� � ����
                date_range.first.month = 1;
                date_range.first.year++;
            }
        }

    }
    profit[date_range.second] += 0;
    auto it_second = profit.find(date_range.second);

    double value_per_day = value / cnt;           // �� � ����
    for (auto it = it_first; it != it_second; it++) {    // ���������� ������� (���������� ��)
        (*it).second += value_per_day;
    }
    (*it_second).second += value_per_day;

}

pair <Date, Date> enter_date() {   // ���� � ������� ���� 

    pair <Date, Date> date_range;
    string year, month, day;

    getline(cin, year, '-');
    getline(cin, month, '-');
    getline(cin, day, ' ');
    date_range.first.day = stoi(day);
    date_range.first.month = stoi(month);
    date_range.first.year = stoi(year);

    getline(cin, year, '-');
    getline(cin, month, '-');
    cin >> day;
    date_range.second.day = stoi(day);
    date_range.second.month = stoi(month);
    date_range.second.year = stoi(year);

    return date_range;

}