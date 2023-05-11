#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <iomanip>

using namespace std;

template <typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith(
    RandomIt range_begin, RandomIt range_end, const string& prefix);

int main() {

    const vector<string> sorted_strings = { "moscow", "motovilikha" , "murmansk" };

    const auto m_result =
        FindStartsWith(begin(sorted_strings), end(sorted_strings), "mo");

    for (auto it = m_result.first; it != m_result.second; ++it) {
        cout << *it << " ";
    }
    cout << endl;

    const auto p_result =
        FindStartsWith(begin(sorted_strings), end(sorted_strings), "mt");
    cout << (p_result.first - begin(sorted_strings)) << " " << (p_result.second - begin(sorted_strings)) << endl;

    const auto z_result =
        FindStartsWith(begin(sorted_strings), end(sorted_strings), "na");
    cout << (z_result.first - begin(sorted_strings)) << " " << (z_result.second - begin(sorted_strings)) << endl;

    return 0;

}

template <typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith(
    RandomIt range_begin, RandomIt range_end, const string& prefix) {

    auto it_begin = lower_bound(range_begin, range_end, prefix); // больше либо равен за лог время

    string next_prefix = prefix;
    auto it = next_prefix.begin() + prefix.size() - 1;
    *it = static_cast<char>((*it) + 1);

    auto it_end = lower_bound(range_begin, range_end, next_prefix);

    return { it_begin, it_end };

}