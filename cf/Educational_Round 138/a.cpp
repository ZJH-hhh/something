#include <iostream>
#include <cstring>
#include <algorithm>

#define x first
#define y second

using PII = std::pair<int, int>;

constexpr int N = 10;

bool stx[N], sty[N];

void solve() {
    memset(stx, 0, sizeof stx);
    memset(sty, 0, sizeof sty);

    int n, m;
    std::cin >> n >> m;

    if (m > n) {
        puts("NO");
        return ;
    }

    int cnt = 0;
    for (int i = 0; i < m; i ++ ) {
        int x, y;
        std::cin >> x >> y;

        if (stx[x] || sty[y]) cnt ++ ; 
    }

    if (cnt == 0 && m == n || cnt > 1) puts("NO");
    else puts("YES");
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;
    while (t -- ) solve();

    return 0;
}