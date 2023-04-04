#include <iostream>
#include <algorithm>
#include <cstring>
#include <unordered_map>

using ll = long long;

const int N = 2e5 + 5;

void solve() {
    int n;
    std::cin >> n;
    int t = 0;
    for (int i = 0; i < n; i ++ ) {
        int x;
        std::cin >> x;
        t ^= x;
    }
    if ((n % 2 == 0) && t || t >= 256) std::cout << "-1\n";
    else std::cout << t << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T = 1;
    std::cin >> T;
    while (T -- ) solve();

    return 0;
}