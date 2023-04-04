#include <iostream>
#include <algorithm>
#include <cstring>
#include <unordered_map>

using ll = long long;

const int N = 1e5 + 5;

int n, m;
int k[N];

void check(int a, int b, int c) {
    int t = std::lower_bound(k, k + n, b) - k;
    if (t < n) {
        int v = k[t];
        if ((ll)(v - b) * (v - b) < 4ll * a * c) {
            std::cout << "YES\n";
            std::cout << v << '\n';
            return ;
        }
    }

    t = std::lower_bound(k, k + n, b) - k;
    t -= 1;
    if (t >= 0) {
        int v = k[t];
        if ((ll)(v - b) * (v - b) < 4ll * a * c) {
            std::cout << "YES\n";
            std::cout << v << '\n';
            return ;
        }
    }
    
    std::cout << "NO\n";
}

void solve() {
    std::cin >> n >> m;
    for (int i = 0; i < n; i ++ ) std::cin >> k[i];
    std::sort(k, k + n);
    while (m -- ) {
        int a, b, c;
        std::cin >> a >> b >> c;
        check(a, b, c);
    }
    std::cout << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T = 1;
    std::cin >> T;
    while (T -- ) solve();

    return 0;
}