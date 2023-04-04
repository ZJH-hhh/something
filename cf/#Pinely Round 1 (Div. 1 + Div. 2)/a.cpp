#include <iostream>
#include <algorithm>
#include <cstring>

using ll = long long;

const int N = 2e5 + 5;

void solve() {
    int n, a, b;
    std::cin >> n >> a >> b;
    if (a + b > n) {
        if (a == b && a == n) puts("YES");
        else puts("NO");
        return ;
    }

    if (a + b == n || a + b == n - 1) {
        puts("NO");
        return ;
    }

    puts("YES");
}

int main() {
    int t = 1;
    std::cin >> t;
    while (t -- ) solve();
    return 0;
}