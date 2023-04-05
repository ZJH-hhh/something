#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using ll = long long;

const int N = 50;

int k, x, y;
int f[N];

void init() {
    f[0] = f[1] = 1;
    for (int i = 2; i < N; i ++ ) f[i] = f[i - 1] + f[i - 2];
}

bool check(int x1, int y1, int x2, int y2) {
    return x >= x1 && x <= x2 && y >= y1 && y <= y2;
}

bool dfs(int x1, int y1, int x2, int y2) {
    int n = x2 - x1 + 1, m = y2 - y1 + 1, len = std::min(n, m);
    if (n == m) {
        if (n == 1 && check(x1, y1, x2, y2)) return true;
        return false; 
    }
    if (m > n) {
        if (check(x1, y1, x2, y2 - len) && dfs(x1, y1, x2, y2 - len)) return true;
        else if(dfs(x1, y1 + len, x2, y2)) return true;
    } else {
        if (check(x1, y1, x2 - len, y2) && dfs(x1, y1, x2 - len, y2)) return true;
        else if(dfs(x1 + len, y1, x2, y2)) return true;
    }
    return false;
}

void solve() {
    std::cin >> k >> x >> y;
    int n = f[k], m = f[k + 1];
    // std::cout << dfs(x, y, x, y) << '\n';
    if (dfs(1, 1, n, m)) std::cout << "YES\n";
    else std::cout << "NO\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);

    init();

    int t = 1;
    std::cin >> t;
    while (t -- ) solve();
    return 0;
}