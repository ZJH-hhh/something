#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

constexpr int N = 2e5 + 5;

int n;
int a[N];

bool check(std::vector<int> a, int k) {
    for (int i = 1; i <= k; i ++ ) {
        std::sort(a.begin(), a.end());
        int pos = std::upper_bound(a.begin(), a.end(), k - i + 1) - a.begin() - 1;
        if (pos < 0) return false;
        a.erase(a.begin() + pos);
        a[0] += k - i + 1;
    }
    
    return true;
}

void solve() {
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i ++ ) std::cin >> a[i];

    int res = n;
    while (res > 0 && !check(a, res)) res -- ;
    
    std::cout << res << '\n';
}   

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;
    while (t -- ) solve();

    return 0;
}