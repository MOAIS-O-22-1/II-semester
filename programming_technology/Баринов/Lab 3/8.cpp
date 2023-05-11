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

bool operator < (const Date& f, const Date& s) {     // перегрузка оператора < 
    if (f.year != s.year) return f.year < s.year;
    else {
        if (f.month != s.month) return f.month < s.month;
        else return f.day < s.day;
    }
}

void condition(map <Date, double>& profit);
void сomputeIncome(map <Date, double>& profit);
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
            сomputeIncome(profit);
        }

        else if (request == "Earn") {
            earn(profit);
        }

        else i--;
    }

}

void сomputeIncome(map <Date, double>& profit) {

    double count_money = 0;                      // счетчик зп
    pair <Date, Date> date_range = enter_date();   // введенные даты

    profit[date_range.first] += 0;
    auto it_first = profit.find(date_range.first);
    profit[date_range.second] += 0;
    auto it_second = profit.find(date_range.second);

    for (auto it = it_first; it != it_second; it++) { // подсчет зп
        count_money += (*it).second;
    }
    count_money += (*it_second).second;   // включая последний день

    cout.precision(5);
    //cout.setf(ios::fixed);
    cout << count_money << endl; 

}

void earn(map <Date, double>& profit) {

    double value;                        // зп за этот промежуток
    pair <Date, Date> date_range = enter_date();
    
    cin >> value;
    calculate(date_range, value, profit);      // распределение зп по дням из промежутка и заполнение словаря

}

void calculate(pair <Date, Date>& date_range, double& value, map <Date, double>& profit) {
    
    vector <int> months = { 31,28,31,30,31,30,31,31,30,31,30,31 };     // дни в месяцах
    auto feb = months.begin() + 1;                // указатель на февраль
    int cnt = 1;

    profit[date_range.first] += 0;
    auto it_first = profit.find(date_range.first);

    while (date_range.first.day != date_range.second.day ||    // создание и подсчет количества дней между датами
        date_range.first.month != date_range.second.month ||
        date_range.first.year != date_range.second.year) {

        profit[date_range.first] += 0;

        if (date_range.first.year % 4 == 0) *feb = 29; // если високосный
        if(date_range.first.year % 4 != 0 && *feb == 29) *feb = 28; // возврат от високосного

        cnt++;

        if (date_range.first.day != *(months.begin() + date_range.first.month - 1)) date_range.first.day++;
        else {                                 // если последний день в месяце
            date_range.first.day = 1;
            date_range.first.month++;
            if (date_range.first.month == 13) { // если последний день в году
                date_range.first.month = 1;
                date_range.first.year++;
            }
        }

    }
    profit[date_range.second] += 0;
    auto it_second = profit.find(date_range.second);

    double value_per_day = value / cnt;           // зп в день
    for (auto it = it_first; it != it_second; it++) {    // заполнение словаря (добавление зп)
        (*it).second += value_per_day;
    }
    (*it_second).second += value_per_day;

}

pair <Date, Date> enter_date() {   // ввод и перевод даты 

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