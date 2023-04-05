#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using ll = long long;

const int N = 2e5 + 5;

int a[N], b[N];

void solve() {
    int n;
    std::cin >> n;
    for (int i = 0; i < n - 1; i ++ ) std::cin >> a[i];
    b[0] = a[0], b[n - 1] = a[n - 2];
    for (int i = 1; i < n - 1; i ++ ) b[i] = std::min(a[i - 1], a[i]);
    for (int i = 0; i < n; i ++ ) std::cout << b[i] << ' ';
    std::cout << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);

    int t = 1;
    std::cin >> t;
    while (t -- ) solve();
    return 0;
}