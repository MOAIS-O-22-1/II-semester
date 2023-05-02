#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ofstream file;
	setlocale(LC_ALL, "Rus");
	file.exceptions(ofstream::badbit | ofstream::failbit);
	/*file.open("text.txt");*/
	try
	{
		file << "GOOD" << endl;
		file.close();
	}
	catch (ofstream::failure)
	{
		cerr << "файл не существует" << endl;
	}
}