#include <iostream>
#include <algorithm>
#include <cstring>
#include <unordered_map>

typedef long long ll;

const int N = 2e5 + 5;

void solve() {
    std::string s;
    std::cin >> s;
    std::unordered_map<char, int> cnt;
    for (auto c: s) cnt[c] ++ ;
    if (cnt.size() == 1) puts("-1");
    else if (cnt.size() == 4 || cnt.size() == 3) puts("4");
    else {
        for (auto [k, v]: cnt) {
            if (v == 2) puts("4");
            else puts("6");
            break;
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);

    int t = 1;
    std::cin >> t;
    while (t -- ) solve();
    return 0;
}