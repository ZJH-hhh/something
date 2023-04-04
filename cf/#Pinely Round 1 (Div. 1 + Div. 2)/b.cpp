#include <iostream>
#include <algorithm>
#include <cstring>
#include <unordered_set>

void solve() {
    int n;
    std::cin >> n;
    std::unordered_set<int> S;
    for (int i = 0; i < n; i ++ ) {
        int x;
        std::cin >> x;
        S.insert(x);
    }

    if (S.size() > 2) std::cout << n << '\n';
    else std::cout << n / 2 + 1 << '\n'; 
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);

    int t = 1;
    std::cin >> t;
    while (t -- ) solve();
    return 0;
}