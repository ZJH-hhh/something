#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using ll = long long;

const int N = 2e5 + 5;

void solve() {
    int n;
    char x;
    std::string s;
    std::cin >> n >> x >> s;
    for (int i = 0; i < s.size(); i ++ ) {
        if (x <= s[i]) continue;
        std::cout << s.substr(0, i) + x + s.substr(i) << '\n';
        return ;
    }
    std::cout << s + x << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);

    int t = 1;
    std::cin >> t;
    while (t -- ) solve();
    return 0;
}