#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <vector>

void solve() {
    int n;
    std::string s;
    std::cin >> n >> s;

    std::vector<int> a(n);
    for (int i = 0; i < n; i ++ ) std::cin >> a[i];

    for (int i = 1, j = 0; i < n; i ++ ) {
        while (i < n && s[i] == '1' && a[i] >= a[j]) i ++ ;
        if (i < n && s[i] == '1' && a[i] < a[j]) std::swap(s[i], s[j]);
        j = i;
    }

    int res = 0;
    for (int i = 0; i < n; i ++ )
        res += s[i] == '1' ? a[i] : 0;
    
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