#include <iostream>
#include <algorithm>
#include <cstring>
#include <unordered_map>
#include <vector>

using ll = long long;

const int N = 2e5 + 5;

void solve() {
    std::vector<int> a(3);
    for (int i = 0; i < 3; i ++ ) std::cin >> a[i];
    std::sort(a.begin(), a.end());
    std::cout << a[1] << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);

    int t = 1;
    std::cin >> t;
    while (t -- ) solve();
    return 0;
}