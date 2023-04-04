#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

constexpr int N = 105;

int n;
int a[N], b[N];

void solve() {
    cin >> n;
    for (int i = 0; i < n; i ++ ) cin >> a[i];
    for (int i = 0; i < n; i ++ ) cin >> b[i];
    
    int cnt1 = 0, cnt2 = 0, diff = 0;
    for (int i = 0; i < n; i ++ ) {
        cnt1 += a[i] == 1;
        cnt2 += b[i] == 1;
        diff += a[i] != b[i];
    }

    if (!diff) cout << 0 << '\n';
    else cout << min(abs(cnt1 - cnt2) + 1, diff) << '\n';
}

int main() {
    int t = 1;
    cin >> t;
    while (t -- ) solve();
    return 0;
}