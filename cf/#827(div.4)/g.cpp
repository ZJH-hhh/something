#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <vector>

constexpr int N = 2e5 + 5;

int n;
int a[N];
bool st[N];

void solve() {
    memset(st, false, sizeof st);
    std::cin >> n;
    for (int i = 0; i < n; i ++ ) std::cin >> a[i];
    std::sort(a, a + n, std::greater<int>());
    std::vector<int> res(1, 0);
    int curOR = a[0];
    st[0] = true;

    while (true) {
        int pos = -1, maxSub = -1;
        for (int i = 0; i < n; i ++ ) {
            if (st[i]) continue;
            if ((a[i] | curOR) - curOR > maxSub) {
                maxSub = (a[i] | curOR) - curOR;
                pos = i;
            }
        }

        if (pos == -1 || maxSub == 0) break;
        st[pos] = true;
        res.emplace_back(pos);
        curOR |= a[pos];
    }

    for (auto& t: res) std::cout << a[t] << ' ';
    for (int i = 0; i < n; i ++ )
        if (!st[i]) std::cout << a[i] << ' ';
    puts("");
}

int main() {
    int t = 1;
    std::cin >> t;
    while (t -- ) solve();
    return 0;
}