#include <iostream>
#include <algorithm>
#include <cstring>
#include <unordered_map>
#include <vector>

using ll = long long;
using PII = std::pair<int, int>;

const int N = 2e5 + 5;

void solve() {
    int n;
    std::cin >> n;

    std::vector<PII> a(n);
    for (int i = 0; i < n; i ++ ) {
        int x;
        std::cin >> x;
        a[i] = {x, i};
    }

    std::sort(a.begin(), a.end());
    std::vector<int> res(n);
    for (int i = 0; i < n; i ++ ) {
        if (i == n - 1) res[a[i].second] = a[i].first - a[n - 2].first;
        else res[a[i].second] = a[i].first - a[n - 1].first;
    }

    for (auto& x: res) std::cout << x << ' ';
    std::cout << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);

    int t = 1;
    std::cin >> t;
    while (t -- ) solve();
    return 0;
}