#include <iostream>
#include <algorithm>
#include <cstring>
#include <unordered_map>
#include <vector>

using ll = long long;

const int N = 2e5 + 5;

void solve() {
    int n, days;
    ll target;
    std::cin >> n >> target >> days;

    std::vector<int> w(n);
    for (int i = 0; i < n; i ++ ) std::cin >> w[i]; 

    std::sort(w.begin(), w.end(), [&](int a, int b) {
        return a > b;
    });

    ll t = 0;
    for (int i = 0; i < days && i < n; i ++ ) t += w[i];
    if (t >= target) {
        std::cout << "Infinity\n";
        return ;
    }

    if (ll(w[0]) * days < target) {
        std::cout << "Impossible\n";
        return ;
    }

    int l = 0, r = N;
    while (l < r) {
        int mid = l + r + 1 >> 1;
        ll sum = 0;
        for (int day = 0, i = 0; day < days; day ++ ) {
            if (i < n) sum += w[i];
            i = (i + 1) % (mid + 1);
        }

        if (sum >= target) l = mid;
        else r = mid - 1;
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