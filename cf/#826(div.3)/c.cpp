#include <iostream>
#include <algorithm>
#include <cstring>
#include <unordered_map>

using namespace std;

using ll = long long ;

constexpr int N = 2e5 + 5, INF = 0x3f3f3f3f;

int n;
int a[N];
ll s[N];

int calc(int limit) {
    int sum = 0, len = 0, res = 0;
    for (int i = 1; i <= n; i ++ ) {
        sum += a[i]; len ++ ;
        if (sum == limit) {
            res = max(res, len);
            sum = len = 0;
        }
        else if (sum > limit) return -1;
    }
    return sum == 0 ? res : -1;
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i ++ ) cin >> a[i], s[i] = s[i - 1] + a[i];

    int res = n;
    for (int i = 1; i <= n; i ++ ) {
        int t = calc(s[i]);
        if (t != -1) res = min(res, t);
    }
    cout << res << '\n';
}
    

int main() {
    int t;
    cin >> t;
    while (t -- ) solve();
    return 0;
}