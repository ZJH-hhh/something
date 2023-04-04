#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

constexpr int N = 2e5 + 5;

int n;
int a[N];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i ++ ) cin >> a[i];

    long long res = 0;
    for (int i = 1, j = 1; i <= n; i ++ ) {
        while (j <= n && a[j] - (j - i + 1) >= 0) j ++ ;
        res += j - i;
    }
    cout << res << '\n';
}

int main() {
    int t = 1;
    cin >> t;
    while (t -- ) solve();
    return 0;
}