#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

constexpr int N = 2e5 + 5;

int n;
int a[N];
bool f[N];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i ++ ) cin >> a[i];

    memset(f, false, sizeof f);
    f[0] = 1;
    for (int i = 1; i <= n; i ++ ) {
        if (i - a[i] >= 1) f[i] |= f[i - a[i] - 1];
        if (i + a[i] <= n) f[i + a[i]] |= f[i - 1];
    }

    puts(f[n] ? "YES" : "NO");
}

int main() {
    int t;
    cin >> t;
    while (t -- ) solve();
    return 0;
}