#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include <utility>
#include <string>
using namespace std;


template <typename T>
T Sqr(T x);

template <typename T>
vector<T> operator *(const vector <T>& x1, const vector <T>& x2);

template <typename First, typename Second>
pair<First, Second> operator*(const pair<First, Second>& x1, const pair<First, Second>& x2);

template <typename Key, typename Value>
map<Key, Value> operator*(const map<Key, Value>& x1, const map<Key, Value>& x2);


template <typename First, typename Second>
pair<First, Second> operator*(const pair<First, Second>& x1, const pair<First, Second>& x2) {
    return make_pair(x1.first * x2.first, x1.second * x2.second);
}
template <typename T>
vector<T> operator *(const vector <T>& x1, const vector <T>& x2) {
    vector <T> res;
    for (int i = 0; i < x1.size(); i++)
        res.push_back(x1[i] * x2[i]);
    return res;
}
template <typename Key, typename Value>
map<Key, Value> operator*(const map<Key, Value>& x1, const map<Key, Value>& x2) {
    vector <Value> x1_values, x2_values;
    map <Key, Value> res = x1;
    for (auto &item: x1) {
        x1_values.push_back(item.second);
    }
    for (auto &item: x2) {
        x2_values.push_back(item.second);
    }
    x1_values = x1_values * x2_values;
    int i = 0;
    for (auto &item:res) {
        item.second = x1_values[i];
        i++;
    }
    return res;
}

template <typename T>
T Sqr(T x) {
    return x * x;
}
int main() {


    vector<int> v = {1, 2, 3};
    cout << "vector:";
    for (int x : Sqr(v)) {
        cout << ' ' << x;
    }
    cout << endl;

    map<int, pair<int, int>> map_of_pairs = {
            {4, {2, 2}},
            {7, {4, 3}}
    };
    cout << "map of pairs:" << endl;
    for (const auto &x : Sqr(map_of_pairs)) {
        cout << x.first << ' ' << x.second.first << ' ' << x.second.second << endl;
    }

}