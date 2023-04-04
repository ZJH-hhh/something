#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <vector>

int C(int n, int m) {
    if (m == 0 || m == n) return 1;
    return C(n - 1, m) + C(n - 1, m - 1);
}

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i ++ ) std::cin >> a[i];

    int res = C(10 - n, 2) * 6;
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