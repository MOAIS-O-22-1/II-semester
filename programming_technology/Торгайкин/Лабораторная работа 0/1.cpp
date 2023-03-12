#include <iostream>
#include <vector>


using namespace std;




pair<size_t, size_t> max_element(const vector<vector<int>>& matrix) 
{
	pair<size_t, size_t> max(0, 0);

	for (size_t i = 0; i < matrix.size(); i++) 
	{
		for (size_t j = 0; j < matrix[0].size(); j++)
		{
			if (matrix[i][j] > matrix[max.first][max.second])
			{
				max.first = i;
				max.second = j;
			}
		}
	}
	return max;
}




int main()
{
	size_t n, m;
	pair <size_t, size_t> max;
	cin >> n >> m;
	vector <vector<int>> matrix(n, vector <int>(m));
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < m; j++)
		{
			cin >> matrix[i][j];

		}
	}
	max = max_element(matrix);
	cout << max.first << " " << max.second << std::endl;


}