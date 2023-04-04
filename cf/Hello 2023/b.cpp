#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

void solve() {
    int n;
    std::cin >> n;
    if (n & 1) {
        std::cout << "NO\n";
        return ;
    }
    std::cout << "YES\n";
    for (int i = 0; i < n; i ++ ) {
        std::cout << (i & 1 ? 1 : -1) << ' ';
    }
    std::cout << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);

    int t = 1;
    std::cin >> t;
    while (t -- ) solve();
    return 0;
}