#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using ll = long long;

const int N = 20;

int a[N];
ll f[N];

ll dp(int pos, bool limit) {
    if (!pos) return 1ll;
    if (!limit && ~f[pos]) return f[pos];
    int up = limit ? a[pos] : 9;
    ll res = 0;
    for (int i = 0; i <= up; i ++ ) {
        if (i == 4) continue;
        res += dp(pos - 1, limit && i == up);
    }
    return limit ? res : f[pos] = res;
}

ll cal(ll x) {
    int len = 0;
    while (x) a[++ len] = x % 10, x /= 10;
    memset(f, -1, sizeof f);
    return dp(len, true);
}

void solve() {
    ll k;
    std::cin >> k;
    ll l = k, r = 1e18;
    while (l < r) {
        ll mid = l + r >> 1;
        if (cal(mid) - 1 >= k) r = mid;
        else l = mid + 1;
    }
    std::cout << r << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);

    int t = 1;
    std::cin >> t;
    while (t -- ) solve();
    return 0;
}