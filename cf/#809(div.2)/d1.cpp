#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>

using namespace std;

typedef long long ll;

const int N = 3005;

int a[N];

void solve(){
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i ++ ) cin >> a[i];

    int res = a[n];
    for (int mi = a[1] / k; mi <= a[1]; mi ++ ){
        int t = 0;
        for (int i = 1; i <= n; i ++ ){
            int y = k;
            if (mi) y = min(a[i] / mi, k);
            int x = a[i] / y;
            t = max(t, x);
        }
        res = min(res, t - mi);
    }
    cout << res << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int t = 1;
    cin >> t;
    while (t -- ) solve();

    return 0;
}