// ������� �����, �����-�-22/1, ��� 9, ������� 8
#include <iostream>
#include <math.h>
using namespace std;


void nat_log(const float &num)
{
	if (num < 0)
	{
		throw("������� �����, ������� ����.");
	}
	if (num == 0)
	{
		throw("������� �����, ������ ����.");
	}
	cout << "�����: ���������� ������ �������." << endl << "���������: " << log(num) << endl;
}


int main() {
	setlocale(LC_ALL, "ru");
	int num;
	cout << "---- ���������� ������������ ��������� �� ����� num ----" << endl;


	try
	{
		cout << "������� �����: ";
		cin >> num;
		nat_log(num);
	}


	catch (const char *ex)
	{
		cout << "������: " << ex << endl;
		cout << "���������: �� ��������." << endl;
	}
}