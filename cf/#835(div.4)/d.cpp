#include <iostream>
#include <algorithm>
#include <cstring>
#include <unordered_map>
#include <vector>

using ll = long long;

const int N = 2e5 + 5;

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> a(n + 2);
    for (int i = 1; i <= n; i ++ ) std::cin >> a[i];
    a[0] = a[n + 1] = 2e9;

    int cnt = 0;
    for (int i = 1; i <= n; i ++ ) {
        if (a[i] < a[i - 1]) {
            int j = i + 1;
            while (j <= n && a[j] == a[i]) j ++ ;
            if (a[i] < a[j]) {
                cnt ++ ;
                if (cnt > 1) {
                    puts("NO");
                    return ;
                }
            }
            i = j - 1;
        }
    }
    puts(cnt == 1 ? "YES": "NO");
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);

    int t = 1;
    std::cin >> t;
    while (t -- ) solve();
    return 0;
}