#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

void z2(const string &a){
    string sl;
    int cnt = 0;
    stringstream str(a);
    while (str >> sl){
        cnt++;
    }
    cout << cnt << endl;
}

int main()
{
    string a;
    getline(cin, a);
    z2(a);
}
