#include <iostream>
#include <vector>


using namespace std;


int main()
{
	int num, min;
	size_t n, k, count = 0, beg = 0, end;
	cin >> n >> k;
	end = k;
	vector <int> arr;

	for (size_t i = 0; i < n; i++)
	{
		cin >> num;
		arr.push_back(num);
	}

	for (size_t i = beg; i < end; i++)
	{
		if (i == beg)
		{
			min = arr[i];
		}
		if (arr[i] < min)
		{
			min = arr[i];
		}
		if (i == end - 1)
		{

			cout << min << endl;
			i = beg;
			end += 1;
			beg += 1;


			count += 1;
		}
		if (count == n - k + 1)
		{
			break;
		}

	}

}