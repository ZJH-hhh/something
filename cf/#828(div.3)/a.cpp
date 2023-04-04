#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <unordered_map>

void solve() {
    int n;
    std::cin >> n;
    
    std::vector<int> a(n);
    std::vector<int, std::vector<int>> b;
    for (int i = 0; i < n; i ++ ) {
        std:: cin >> a[i];
        b[a[i]].emplace_back(i);
    }

    std::string s;
    std::cin >> s;

    for (int i = 0; i < b.size(); i ++ ) {
        for (int j = 0; j < b[i].size(); j ++ ) {
            if (s[b[i][j]] != s[b[i][0]]) {
                puts("NO");
                return ;
            }
        }
    }    
    puts("YES");
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;
    while (t -- ) solve();
    
    return 0;
}