#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <vector>

void solve() {
    int n;
    std::cin >> n;
    
    std::vector<int> res;
    res.emplace_back(1);
    for (int i = n; i > 1; i --) res.emplace_back(i);

    for (auto t: res) std::cout << t << ' ';
    std::cout << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;
    while (t -- ) solve();

    return 0;
}