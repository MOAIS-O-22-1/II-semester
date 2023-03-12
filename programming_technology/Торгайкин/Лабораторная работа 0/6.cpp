#include <iostream>
#include <string>
#include <vector>
#include <algorithm>




using namespace std;



struct student
{
	string name;
	string surname;
	int day;
	int month;
	int year;
};



bool surname_and_name(const student& s1, const student& s2)
{
	if (s1.surname < s2.surname)
	{
		return s1.surname < s2.surname;
	}
	else if (s1.surname == s2.surname)
	{
		if (s1.name < s2.name)
		{
			return s1.name > s2.name;
		}
		else if (s1.name == s2.name)
		{
			if (s1.year < s2.year)
			{
				return s1.year < s2.year;
			}
			else if (s1.year == s2.year)
			{
				if (s1.month < s2.month)
				{
					return s1.month < s2.month;
				}
				else if (s1.month == s2.month)
				{
					if (s1.day < s2.day)
					{
						return s1.day < s2.day;
					}
					else { return 0; }
				}
				else { return 0; }
			}
			else { return 0; }


		}
		else { return 0; }
	}
	else { return 0; }

}
bool year_month_day(const student& s1, const student& s2)
{
	if (s1.year < s2.year)
	{
		return s1.year < s2.year;
	}
	else if (s1.year == s2.year)
	{
		if (s1.month < s2.month)
		{
			return s1.month < s2.month;
		}
		else if (s1.month == s2.month)
		{
			if (s1.day < s2.day)
			{
				return s1.day < s2.day;
			}
			else if (s1.day == s2.day)
			{
				if (s1.surname < s2.surname)
				{
					return s1.surname > s2.surname;
				}
				else if (s1.surname == s2.surname)
				{
					if (s1.name < s2.name)
					{
						return s1.name < s2.name;
					}
					else
					{
						return 0;
					}
				}
				else
				{
					return 0;
				}
			}
			else { return 0; }


		}
		else { return 0; }
	}
	else 
	{
		return 0;
	}

}
void Sorted(vector<student>& students, const string& sort_met)
{
	if (sort_met == "date")
	{
		sort(students.begin(), students.end(), year_month_day);
	}
	if (sort_met == "name")
	{
		sort(students.begin(), students.end(), surname_and_name);
	}
	for (size_t i = 0; i < students.size(); i++)
	{
		cout << students[i].surname << " " << students[i].name << " " << students[i].day << "." << students[i].month << "." << students[i].year << endl;
	}
	
}


int main()
{
	string sort_met, name, surname;
	int day, month, year;
	size_t n;
	cin >> n;
	vector <student> students;
	
	
	for (size_t i = 0; i < n; i++)
	{
		cin >> name >> surname >> day >> month >> year;
		students.push_back({ name, surname, day, month, year });
	}
	cin >> sort_met;
	cout << endl;
	Sorted(students, sort_met);

}