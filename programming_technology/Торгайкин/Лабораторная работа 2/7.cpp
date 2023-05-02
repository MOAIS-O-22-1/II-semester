#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>




using namespace std;

template <typename InIter1, typename InIter2, typename OutIter>
OutIter Set_difference(InIter1 first1, InIter1 last1, InIter2 first2, InIter2 last2, OutIter out)
{
	for (auto& i = first1, j = first2; i != last1 && j != last2;)
	{
		if (*i > *j)
		{
			j++;
		}
		else if (*i < *j)
		{
			*out = *i;
			i++;
			out++;
		}
		else
		{
			i++;
			j++;
		}
	}

	if (first1 == last1)
	{
		return out;
	}
	else
	{
		return copy(first1, last1, out);
	}

}



int main()
{
	vector <int> arr1 = { 16, 36, 42, 98, 123, 150, 160 };
	vector <int> arr2 = { 15, 34, 98, 100 };
	sort(arr1.begin(), arr1.end());
	sort(arr2.begin(), arr2.end());
	vector <int> arr(arr1.size() + arr2.size());
	vector <int> ::iterator it;
	it = Set_difference(arr1.begin(), arr1.end(), arr2.begin(), arr2.end(), arr.begin());
	arr.erase(it, arr.end());
	for (const auto& i : arr)
	{
		cout << i << " ";
	}
}