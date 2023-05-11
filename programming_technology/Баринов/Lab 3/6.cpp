#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

enum class Gender { 
    FEMALE, MALE 
};
struct Person {
    int age;    // возраст
    Gender gender;    // пол
    bool is_employed;    // имеет ли работу
};

template <typename InputIt>
int ComputeMedianAge(InputIt range_begin, InputIt range_end);

void PrintStats(vector<Person> persons);

int main() {
    
    vector <Person> persons = {
        {31, Gender::MALE, false},
        {40, Gender::FEMALE, true},
        {24, Gender::MALE, true},
        {20, Gender::FEMALE, true},
        {80, Gender::FEMALE, false},
        {78, Gender::MALE, false},
        {10, Gender::FEMALE, false},
        {55, Gender::MALE, true},
    };
    PrintStats(persons);

    return 0;
}

void PrintStats(vector <Person> persons) {

    cout << "Median age = " << ComputeMedianAge(persons.begin(), persons.end()) << endl;

    auto it = partition(persons.begin(), persons.end(), [](Person i) {return i.gender == Gender::FEMALE; });
    cout << "Median age for females = " << ComputeMedianAge(persons.begin(), it) << endl; // все женщины

    it = partition(persons.begin(), persons.end(), [](Person i) {return i.gender == Gender::MALE; });
    cout << "Median age for males = " << ComputeMedianAge(persons.begin(), it) << endl; // все мужчины

    it = partition(persons.begin(), persons.end(), [](Person i) {return i.gender == Gender::FEMALE && i.is_employed == true; });
    cout << "Median age for employed females = " << ComputeMedianAge(persons.begin(), it) << endl; // все занятые женщины

    it = partition(persons.begin(), persons.end(), [](Person i) {return i.gender == Gender::FEMALE && i.is_employed == false; });
    cout << "Median age for unemployed females= " << ComputeMedianAge(persons.begin(), it) << endl; // все безработные женщины

    it = partition(persons.begin(), persons.end(), [](Person i) {return i.gender == Gender::MALE && i.is_employed == true; });
    cout << "Median age for employed males = " << ComputeMedianAge(persons.begin(), it) << endl; // все занятые мужчины

    it = partition(persons.begin(), persons.end(), [](Person i) {return i.gender == Gender::MALE && i.is_employed == false; });
    cout << "Median age for unemployed males = " << ComputeMedianAge(persons.begin(), it) << endl; // все безработные мужчины

}

template <typename InputIt>
int ComputeMedianAge(InputIt range_begin, InputIt range_end) {

    sort(range_begin, range_end, [](Person n1, Person n2) { return n1.age < n2.age; });

    return (*(range_begin + distance(range_begin, range_end)/2)).age;

}