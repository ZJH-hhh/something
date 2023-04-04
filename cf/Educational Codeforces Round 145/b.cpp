#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>

typedef long long ll;

const int N = 1e5 + 5;

void solve() {
    ll n;
    std::cin >> n;
    ll t = sqrtl(n);
    if (t * t == n) std::cout << t - 1 << '\n';
    else std::cout << t << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);

    int t = 1;
    std::cin >> t;
    while (t -- ) solve();
    return 0;
}