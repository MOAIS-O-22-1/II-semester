#include <iostream>
#include <string>
#include <queue>
#include <iterator>
#include <vector>
#include <list>



using namespace std;

template <typename It, typename Pred>
bool Any_of(It first, It last, Pred f)
{
	for (auto i = first; i != last; i++)
	{
		if (f(*(i)) == true)
		{
			return true;
		}

	}
	return false;
}

bool f(int i)
{
	if (i == 1)
	{
		return true;
	}
	return false;

}

int main()
{
	vector <int> arr{ 123, 100, 12, 54, 12 };
	if (Any_of(arr.begin(), arr.end(), f))
	{
		cout << "GOOD" << endl;
	}
	else
	{
		cout << "BAD" << endl;
	}

}