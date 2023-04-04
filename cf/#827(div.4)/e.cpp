#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>

using namespace std;

using ll = long long;

constexpr int N = 2e5 + 5;

int n, q;
int a[N], b[N];
ll s[N]; 

void solve() {
    cin >> n >> q;
    for (int i = 1; i <= n; i ++ ) {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
        b[i] = max(b[i - 1], a[i]);
    }

    while (q -- ) {
        int x;
        cin >> x;
        int pos = upper_bound(b + 1, b + 1 + n, x) - b;
        cout << s[pos - 1] << ' ';
    }
    puts("");
}

int main() {
    int t = 1;
    cin >> t;
    while (t -- ) solve();
    return 0;
}