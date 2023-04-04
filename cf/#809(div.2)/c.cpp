#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>

using namespace std;

typedef long long ll;

const int N = 1e5 + 5;

int a[N];
ll s1[N], s2[N];

void solve(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++ ){
        cin >> a[i];
        s1[i] = s2[i] = 1e18;
    }

    if (n & 1){
        ll res = 0;
        for (int i = 2; i <= n - 1; i += 2)
            res += max(0, max(a[i - 1], a[i + 1]) - a[i] + 1);
        cout << res << '\n';
        return ;
    }

    ll sum = 0;
    for (int i = 2; i <= n - 1; i += 2){
        sum += max(0, max(a[i - 1], a[i + 1]) - a[i] + 1);
        s1[i] = min(s1[i], sum);
    }
    sum = 0;
    for (int i = n - 1; i >= 2; i -= 2){
        sum += max(0, max(a[i - 1], a[i + 1]) - a[i] + 1);
        s2[i] = min(s2[i], sum);
    }

    ll res = min(s1[n - 2], s2[3]);
    for (int i = 2; i + 3 <= n; i ++ ) res = min(res, s1[i] + s2[i + 3]);
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