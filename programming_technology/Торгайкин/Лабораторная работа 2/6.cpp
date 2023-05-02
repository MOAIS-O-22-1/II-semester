#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>




using namespace std;

template <typename InIter, typename OutIter, typename Predicate>
OutIter Remove_copy_if(InIter first, InIter last, OutIter out, Predicate f)
{
	for (auto& i = first; i != last; i++)
	{
		if (f(*i) == false)
		{
			*out = *i;
			out++;
		}
	}
	return out;
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
	vector <int> arr1 = { 14, 12, 54 , 9 , 1, 1, 1, 145, 1 };
	vector <int> arr2(arr1.size());
	Remove_copy_if(arr1.begin(), arr1.end(), arr2.begin(), f);
	for (const auto& i : arr2)
	{
		cout << i << " ";
	}
}