#include <iostream>
#include <algorithm>
#include <cstring>
#include <unordered_map>

using namespace std;

using ll = long long ;
using pii = pair<int, int>;

constexpr int N = 3e5 + 5, INF = 1e9;

int n;
int a[N];
ll res;

pii dfs(int l, int r) {
    if (l == r) return {a[l], a[l]};
    int mid = l + r >> 1;
    auto [x1, y1] = dfs(l, mid);
    auto [x2, y2] = dfs(mid + 1, r);
    if (y2 + 1 == x1) res ++ ;
    else if (y1 != x2 - 1) res = INF;
    int minv = min({x1, x2}), maxv = max({y1, y2});
    return {minv, maxv};
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i ++ ) cin >> a[i];
    res = 0;
    dfs(0, n - 1);
    if (res >= INF) res = -1;
    cout << res << '\n';
}
    

int main() {
    int t;
    cin >> t;
    while (t -- ) solve();
    return 0;
}