#include <iostream>
#include <algorithm>
#include <cstring>
#include <set>
#include <vector>
#include <functional>

using ll = long long;

const int N = 2e5 + 5;

int h[N], e[N], w[N], ne[N], idx;

void add(int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++ ;
}

void solve() {
    idx = 0;
    memset(h, -1, sizeof h);

    int n, a, b;
    std::cin >> n >> a >> b;
    for (int i = 0; i < n - 1; i ++ ) {
        int u, v, w;
        std::cin >> u >> v >> w;
        add(u, v, w), add(v, u, w);
    }

    std::set<int> S;
    bool flag = false;
    std::function<void(int, int, int)> dfsa = [&](int u, int fa, int cur) {
        S.insert(cur);
        for (int i = h[u]; ~i; i = ne[i]) {
            int j = e[i];
            if (j == fa || j == b) continue;
            dfsa(j, u, cur ^ w[i]);
        }
    };

    std::function<void(int, int, int)> dfsb = [&](int u, int fa, int cur) {
        for (int i = h[u]; ~i; i = ne[i]) {
            int j = e[i];
            if (j == fa) continue;
            if (S.count(cur ^ w[i])) {
                flag = true;
                return ;
            }
            dfsb(j, u, cur ^ w[i]);
        }
    };

    dfsa(a, 0, 0);
    dfsb(b, 0, 0);
    std::cout << (flag ? "YES": "NO") << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;
    while (t -- ) solve();
    return 0;
}