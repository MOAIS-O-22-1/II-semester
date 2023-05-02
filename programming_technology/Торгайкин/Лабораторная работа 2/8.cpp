#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <list>




using namespace std;

template <typename It, typename OutputIt>
OutputIt Sideways_merge(It first1, It last1, It first2, It last2, OutputIt out)
{

	--last2;

	while (first2 != last2 && first1 != last1)
	{


		if (*first1 < *last2)
		{
			*out = *first1;
			out++;
			first1++;
		}
		else if (*first1 > *last2)
		{
			*out = *last2;
			out++;
			last2--;
		}
		else
		{
			*out = *first1;
			out++;
			*out = *last2;
			out++;
			first1++;
			last2--;

		}

	}
	if (first1 == last1)
	{
		return reverse_copy(first2, last2 + 1, out);
	}
	else if (first2 == last2)
	{
		while (first1 != last1)
		{
			if (*first1 < *last2)
			{
				*out = *first1;
				first1++;
				out++;
			}
			else
			{
				*out = *last2;
				out++;
				return copy(first1, last1, out);
			}


		}


	}
	return out;



}

int main()
{
	vector <int> arr1 = { 5, 10, 15, 40, 50, 70 };
	vector <int> arr2 = { 128, 123, 70, 38, 25, 10, 5 };
	vector <int> arr(arr1.size() + arr2.size());

	Sideways_merge(begin(arr1), end(arr1), begin(arr2), end(arr2), begin(arr));

	for (const auto& i : arr)
	{
		cout << i << " ";
	}
}