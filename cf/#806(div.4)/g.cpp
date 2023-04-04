#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

typedef long long ll;

const int N = 1e5 + 5;
int a[N];


void solve(){
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n ; i ++ ) cin >> a[i];

    ll res = 0, sum = 0;
    for (int i = -1; i < n; i ++ ){
        ll tmp = sum;
        for (int j = i + 1; j < min(n, i + 32); j ++ ){
            int t = a[j];
            t >>= j - i;
            tmp += t;
        }
        res = max(res, tmp);
        if (i + 1 < n) sum += a[i + 1] - k;
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