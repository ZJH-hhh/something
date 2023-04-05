#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using ll = long long;

const int N = 2e5 + 5;

void solve() {
    int n, x1, y1, x2, y2;
    std::cin >> n >> x1 >> y1 >> x2 >> y2;
    int a = std::min({x1, y1, n - x1 + 1, n - y1 + 1});
    int b = std::min({x2, y2, n - x2 + 1, n - y2 + 1});
    std::cout << abs(a - b) << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);

    int t = 1;
    std::cin >> t;
    while (t -- ) solve();
    return 0;
}