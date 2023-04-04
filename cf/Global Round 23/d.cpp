#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using ll = long long;

void solve() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> p(n), g(n);
    for (int i = 1; i < n; i ++ ) {
        std::cin >> p[i];
        g[p[i]].emplace_back(i);
    }

    std::vector<int> s(n);
    for (int i = 0; i < n; i ++ ) {
        std::cin >> s[i];
    }

    
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin_tie(nullptr);

    int t = 1;
    std::cin >> t;
    while (t -- ) solve();

    return 0;
}