#include <iostream>
#include <algorithm>
#include <cstring>
#include <unordered_map>

using ll = long long;

const int N = 2e5 + 5;

void solve() {
    int n;
    std::string s;
    std::cin >> n >> s;
    char minv = 'z';
    for (auto &c: s)  minv = std::min(minv, c);
    for (int i = s.size() - 1; i >= 0; i -- )
        if (s[i] == minv) {
            std::cout << s.substr(i, 1) + s.substr(0, i) + s.substr(i + 1) << '\n';
            return ;
        }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T = 1;
    std::cin >> T;
    while (T -- ) solve();

    return 0;
}