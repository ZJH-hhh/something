#include <iostream>
#include <cstring>
#include <algorithm>

using LL = long long;

constexpr int N = 2e5 + 5;

void solve() {
    int n;
    std::cin >> n;

    LL res = 0;
    for (int i = 1; i <= n; i ++ ) {
        int x;
        std::cin >> x;
        res += x;
    }
    
    int maxv = -1;
    for (int i = 1; i <= n; i ++ ) {
        int x;
        std::cin >> x;
        res += x;
        maxv = std::max(maxv, x);
    }

    std::cout << res - maxv << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;
    while (t -- ) solve();

    return 0;
}