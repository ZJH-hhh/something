#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using ll = long long;

const int N = 1e5 + 5;

int n, c;
std::vector<int> e[N];

void dfs(int u, int fa, std::vector<int> &d) {
    for (auto& v: e[u]) {
        if (v == fa) continue;
        d[v] = d[u] + 1;
        if (d[v] > d[c]) c = v;
        dfs(v, u, d);
    }
}

void solve() {
    std::cin >> n;
    for (int i = 1; i < n; i ++ ) {
        int a, b;
        std::cin >> a >> b;
        a -- , b -- ;
        e[a].emplace_back(b), e[b].emplace_back(a);
    }

    std::vector<int> d1(n), d2(n);
    dfs(1, -1, d1);
    d1[c] = 0;
    dfs(c, -1, d1);
    d2[c] = 0;
    dfs(c, -1, d2);

    for (int i = 0; i < n; i ++ ) d2[i] = std::max(d2[i], d1[i]);

    int res = 0;
    std::sort(d2.begin(), d2.end());
    for (int k = 1; k <= n; k ++ ) {
        while (res < n && d2[res] < k) res ++ ;
        std::cout << std::min(res + 1, n) << " \n"[k == n];
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);

    int T = 1;
    // std::cin >> T;
    while (T -- ) solve();

    return 0;
}