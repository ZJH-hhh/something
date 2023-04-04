#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <cstdio>

#define read freopen("input.txt", "r", stdin);
#define out freopen("output.txt", "w", stdout);
 
using ll = long long;

const int N = 1e5 + 5;

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n, -1000);
    int t = 0;
    while ((t + 2) * (t + 1) / 2 <= k) t ++ ;
    for (int i = 0; i < t; i ++ ) a[i] = 1;
    k -= t * (t + 1) / 2;
    if (k) {
        a[t] = k - t - 1;
        a[k - 1] = 500;
    }
    for (int x: a) std::cout << x << ' ';
    std::cout << '\n';
    // puts("");
}

int main() {
    read
    out
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);

    int t = 1;
    std::cin >> t;
    while (t -- ) solve();

    // fclose(stdin);
    // fclose(stdout);
    return 0;
}