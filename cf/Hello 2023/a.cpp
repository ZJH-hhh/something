#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

void solve() {
    int n;
    std::string s;
    std::cin >> n >> s;
    bool flag = false;
    for (int i = 1; i < s.size(); i ++ ) {
        if (s[i] != s[i - 1]) flag = true;
        if (s[i] == 'R' && s[i - 1] == 'L') {
            std::cout << i << '\n';
            return ;
        }
    }
    std::cout << (flag ? 0 : -1) << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;
    while (t -- ) solve();
    return 0;
}