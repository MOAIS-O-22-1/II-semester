#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

pair<size_t, size_t> max_element(vector < vector<int> >& matrix);

int main() {

    setlocale(LC_ALL, "ru");
    int n, m;
    vector < vector<int> > matrix;

    cout << "¬ведите кол-во строк и столбцов: ";
    cin >> n >> m;
    
    cout << "¬ведите матрицу:" << endl;
    for (size_t i = 0; i < n; i++) {
        vector <int> tmp;
        for (size_t j = 0; j < m; j++) {
            int a;
            cin >> a;
            tmp.push_back(a);
        }
        matrix.push_back(tmp);
    }

    cout << max_element(matrix).first << " " << max_element(matrix).second << endl;
    system("pause");
    return 0;

}

pair<size_t, size_t> max_element(vector < vector<int> >& matrix) {

    pair<size_t, size_t> element_index;
    int max_elem = matrix[0][0];
    for (size_t i = 0; i < matrix.size(); i++) {
        for (size_t j = 0; j < matrix[0].size(); j++) {
            if (matrix[i][j] > max_elem) {
                max_elem = matrix[i][j];
                element_index = make_pair(i, j);
            }
        }
    }
    return element_index;

}