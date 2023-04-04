#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <vector>

void solve() {
    int n;
    std::string s;
    std::cin >> n >> s;

    if (s.find("0") == -1) {
        std::cout << (1 << int(s.size())) << '\n';
        return ;
    }
    if (s.find("1") == -1) {
        std::cout << 0 << '\n';
        return ;
    }

    for (int i = 0; i < s.size(); i ++ )
        if (s[i] == '1') {
            s = s.substr(i);
            break;
        }
    
    std::string p;
    int pos = 0;
    for (int i = 0; i < s.size(); i ++ )
        if (s[i] == '0') {
            p = s.substr(i);
            pos = i;
            break;
        }
    
    std::string t = s.substr(0, pos);
    std::string res = s;
    int len = n - pos + 1;

    for (int i = 0; i < pos; i ++ ) {
        int j = i + len - 1;
        std::string tmp = p;
        for (int k = i, u = 0; k <= j; k ++ , u ++ )
            if (s[k] == '1') tmp[u] = '1';
        res = std::max(res, t + tmp);
    }

    std::cout << res << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    // std::cin >> t;
    while (t -- ) solve();

    return 0;
}