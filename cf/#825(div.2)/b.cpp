#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

constexpr int N = 1e5 + 5;

int n;
int a[N], b[N];

int lcm(int a, int b) {
    return a * b / __gcd(a, b);
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i ++ ) cin >> a[i];
    if (n <= 2) {
        puts("YES");
        return ;
    }

    b[0] = a[0], b[n] = a[n - 1];
    for (int i = 1; i < n; i ++ ) b[i] = lcm(a[i - 1], a[i]);
    for (int i = 0; i < n; i ++ )
        if (__gcd(b[i], b[i + 1]) != a[i]) {
            puts("NO");
            return ;
        }
    
    puts("YES");
}

int main() {
    int t = 1;
    cin >> t;
    while (t -- ) solve();
    return 0;
}