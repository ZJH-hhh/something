#include <iostream>
#include <algorithm>
#include <cstring>

using ll = long long;

const int N = 2e5 + 5;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T = 1;
    std::cin >> T;
    while (T -- ) solve();

    return 0;
}