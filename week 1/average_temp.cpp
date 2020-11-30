#include <iostream>
#include <numeric>
#include <cstdint>
#include <vector>
#include<algorithm>

using namespace std;
int main() {
    int64_t N;
    cin >> N;
    vector<int64_t> temperatures;
    vector <int64_t> upon_average;
    for (int64_t i = 0; i < N; i++) {
        int64_t temperature = 0;
        cin >> temperature;
        temperatures.push_back(temperature);
    }
    int64_t sum_of_elems = accumulate(temperatures.begin(), temperatures.end(),
                                   decltype(temperatures)::value_type(0));
    int64_t average = sum_of_elems/ static_cast<int>(temperatures.size());
    int count = 0;
    for (int64_t i = 0; i < N; i++) {
        if (temperatures[i] > average) {
            count++;
            upon_average.push_back(i);
        }
    }
    cout << count <<endl;
    for (auto &item:upon_average) {
        cout << item << ' ';
    }
    return 0;
}

