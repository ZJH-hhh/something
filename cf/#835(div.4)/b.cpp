#include <iostream>
#include <algorithm>
#include <cstring>
#include <unordered_map>
#include <vector>
 
using ll = long long;
 
const int N = 2e5 + 5;
 
void solve() {
    int n;
    std::string s;
    std::cin >> n >> s;
    int res = -1;
    for (int i = 0; i < n; i ++ ) {
        if (s[i] - 'a' + 1 > res) res = s[i] - 'a' + 1;
    }
    std::cout << res << '\n';
}
 
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
 
    int t = 1;
    std::cin >> t;
    while (t -- ) solve();
    return 0;
}