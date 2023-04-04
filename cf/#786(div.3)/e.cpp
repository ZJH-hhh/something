#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 200010, INF = 1e8;

int a[N];

void solve(){
    int n;
    cin >> n;

    int min1 = INF, min2 = INF;
    for (int i = 0; i < n; i ++ ){
        cin >> a[i];
        if (a[i] < min1) min2 = min1, min1 = a[i];
        else if (a[i] < min2) min2 = a[i];
    }

    int res = (min1 + 1 >> 1) + (min2 + 1 >> 1);
    for (int i = 0; i + 2 < n; i ++ ){
        int t1 = a[i], t2 = a[i + 2];
        int mi = min(t1, t2), ma = max(t1, t2);
        res = min(res, mi + (ma - mi + 1 >> 1));
    }

    for (int i = 0; i + 1 < n; i ++ ){
        int t1 = a[i], t2 = a[i + 1];
        if (t1 < t2) swap(t1, t2);
        if (t1 > t2 << 1) res = min(res, t1 + 1 >> 1);
        else res = min(res, (t1 + t2 + 2) / 3);
    }

    cout << res << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t -- ) solve();

    return 0;
}