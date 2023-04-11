#include <iostream>
#include <queue>
#include <map>
#include <vector>

using namespace std;

map <string, int> make_products(const size_t& m, map <string, int>& products);
vector <pair<string, int> > make_queue(const size_t& n, vector <pair<string, int> >& queue_list);
int count_of_minutes(vector < pair<string, int> >& queue_list, map <string, int>& products);

int main() {

    int m, n, minute = 0;
    map <string, int> products;
    vector < pair<string, int> > queue_list;

    cin >> m;
    products = make_products(m, products);

    cin >> n;
    queue_list = make_queue(n, queue_list);

    minute = count_of_minutes(queue_list, products);

    cout << minute << endl;

    return 0;

}

map <string, int> make_products(const size_t& m, map <string, int>& products) {

    string of, prod;
    int count;
    for (size_t i = 0; i < m; i++) {
        cin >> count >> of >> prod;
        products[prod] = count;
    }

    return products;

}

vector <pair<string, int> > make_queue(const size_t& n, vector <pair<string, int> >& queue_list) {

    string of, prod;
    int count;
    for (size_t i = 0; i < n; i++) {
        cin >> count >> of >> prod;
        pair<string, int> tmp;
        tmp.first = prod;
        tmp.second = count;
        queue_list.push_back(tmp);
    }

    return queue_list;

}

int count_of_minutes(vector < pair<string, int> >& queue_list, map <string, int>& products) {

    int minute = 0, step = 0;
    while (step != queue_list.size()) {

        if (products.find(queue_list[step].first) == products.end() || products[queue_list[step].first] == 0) 
            step++;

        else if (products[queue_list[step].first] >= queue_list[step].second) {
            products[queue_list[step].first] -= queue_list[step].second;
            step++;
        }

        else if (products[queue_list[step].first] < queue_list[step].second) {
            if (step == queue_list.size() - 1) {
                minute++;
                break;
            }
            queue_list[step].second = products[queue_list[step].first];
            pair<string, int> swap_tmp = queue_list[step];
            queue_list[step] = queue_list[step + 1];
            queue_list[step + 1] = swap_tmp;
        }

        minute++;
    }

    return minute;

}