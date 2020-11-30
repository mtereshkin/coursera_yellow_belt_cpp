#include <iostream>
#include <numeric>
#include <cstdint>
#include <vector>
#include<algorithm>

using namespace std;
int main() {
    int64_t N, R, W, H, D;
    uint64_t result_mass = 0;
    cin >> N >> R;
    for (int i = 0; i < N; i++) {
        cin >> W >> H >> D;
        result_mass += W * H * D * R;
    }
    cout << result_mass;
    return 0;
}
