#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using ll = long long;

const int N = 3e5 + 5;

ll cal(std::vector<int> &a) {
    std::sort(a.begin(), a.end());
    ll sum = 0, res = 0;
    for (int i = 0; i < a.size(); i ++ ) {
        res += (ll)i * a[i] - sum;
        sum += a[i];
    }
    return res;
}

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> a(m, std::vector<int>());
    for (int i = 0; i < n; i ++ )
        for (int j = 0; j < m; j ++ ) {
            int x;
            std::cin >> x;
            a[j].emplace_back(x);
        }

    ll res = 0;
    for (int i = 0; i < m; i ++ ) res += cal(a[i]);
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