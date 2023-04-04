#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>

using namespace std;

constexpr int N = 2e5 + 5, M = 1005;

int n;
int a[N], s[M];

void solve() {
    memset(s, 0, sizeof s);
    cin >> n;
    for (int i = 1; i <= n; i ++ ) {
        cin >> a[i];
        s[a[i]] = i ;
    }

    int res = -1;
    for (int i = 1; i <= 1000; i ++ ) 
        if (s[i]) {
            for (int j = 1; j <= 1000; j ++ )
                if (s[j] && __gcd(i, j) == 1)
                    res = max(res, s[i] + s[j]);
        }

    cout << res << "\n";
}

int main() {
    int t = 1;
    cin >> t;
    while (t -- ) solve();
    return 0;
}