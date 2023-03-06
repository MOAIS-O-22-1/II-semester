#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct Student {
    string Name;
    string Soname;
    int Day;
    int Month;
    int Year;
};

vector <Student> make_students();

bool comp_name(const Student& std1, const Student& std2);
bool comp_date(const Student& std1, const Student& std2);

void sort_by_command(vector<Student> students);

int main() {

    vector<Student> students = make_students();

    sort_by_command(students);

    system("pause");
    return 0;

}

vector<Student> make_students() {
    
    cout << "Enter the number of students: ";
    vector<Student> students;
    int n;
    cin >> n;
    cout << "Enter students:" << endl;
    for (int i = 0; i < n; ++i) {
        string name, soname;
        int day, month, year;
        cin >> name >> soname >> day >> month >> year;
        students.push_back({ name, soname, day, month, year });
    }

    return students;

}

bool comp_name(const Student& std1, const Student& std2) {
    if (std1.Soname != std2.Soname) return std1.Soname < std2.Soname;
    else return std1.Name < std2.Name;
    if ((std1.Soname == std2.Soname) && (std1.Name == std2.Name)) return comp_date;
}
bool comp_date(const Student& std1, const Student& std2) {
    if (std1.Year != std2.Year) return std1.Year < std2.Year;
    else {
        if (std1.Month != std2.Month) return std1.Month < std2.Month;
        else {
            if (std1.Day != std2.Day) return std1.Day < std2.Day;
            else return comp_name;
        }
    }
}

void sort_by_command(vector<Student> students) {

    string command;
    cout << "Enter command: ";
    cin >> command;
    switch (command[0]) {
        case 'n': {
            sort(students.begin(), students.end(), comp_name);
            for (auto i : students) cout << i.Name << " " << i.Soname 
                << " " << i.Day << "." << i.Month << "." << i.Year << endl;
            break;
        }
        case 'd': {
            sort(students.begin(), students.end(), comp_date);
            for (auto i : students) cout << i.Name << " " << i.Soname
                << " " << i.Day << "." << i.Month << "." << i.Year << endl;
            break;
        }
        default: cout << "Error!" << endl; break;
    }

}