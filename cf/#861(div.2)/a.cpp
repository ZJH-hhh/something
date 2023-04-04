#include <iostream>
#include <algorithm>
#include <cstring>

using ll = long long;

const int N = 2e5 + 5;

void solve() {
    int l, r;
    std::cin >> l >> r;
    r = std::min(r, l + 100);
    int res = 0, diff = 0;
    for (int i = l; i <= r; i ++ ) {
        int j = i;
        int maxv = 0, minv = 9;
        while (j) {
            maxv = std::max(maxv, j % 10);
            minv = std::min(minv, j % 10);
            j /= 10;
        }
        if (maxv - minv >= diff) {
            diff = maxv - minv;
            res = i;
        }
    }
    std::cout << res << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;
    while (t -- ) solve();

    return 0;
}