#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include <cmath>
#include <iomanip>
using namespace std;
vector <int> func1(int x1, int y1, int x2, int y2) {
	return { y2 - y1,x1 - x2,(y1 - y2) * x1 + y1 * (x2 - x1) };
}
double func2(int x1, int y1, int x2, int y2, int x3, int y3) {
	vector <int> v1 = func1(x1, y1, x2, y2);
	return abs(v1[0] * x3 + v1[1] * y3 + v1[2]) / sqrt(v1[0] * v1[0] + v1[1] * v1[1]);
}
int main() {
	int x1, x2, x3, x4, x5, y1, y2, y3, y4, y5;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4 >> x5 >> y5;
	vector <double> rast;
	rast.push_back(func2(x1, y1, x2, y2, x5, y5));
	rast.push_back(func2(x2, y2, x3, y3, x5, y5));
	rast.push_back(func2(x3, y3, x4, y4, x5, y5));
	rast.push_back(func2(x4, y4, x1, y1, x5, y5));
	cout << rast[*min(rast.begin(), rast.end()) - 1];
	return 0;
}