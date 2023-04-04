#include <iostream>
#include <algorithm>
#include <cstring>

typedef long long ll;

int gcd(int a, int b) {
    return b ? a % b : gcd(b, a % b);
}

void solve() {
    int n;
    std::cin >> n;
    
}

int main() {
    int t = 1;
    std::cin >> t;
    while (t -- ) solve();
    return 0;
}