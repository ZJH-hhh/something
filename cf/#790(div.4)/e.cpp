#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 150005;

int a[N], s[N];

bool cmp(int a, int b){
    return a > b;
}

void solve(){
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i ++ ) cin >> a[i];

    sort(a + 1, a + 1 + n, cmp);

    for (int i = 1; i <= n; i ++ ) s[i] = s[i - 1] + a[i];

    while (m -- ){
        int x;
        cin >> x;
        int res = lower_bound(s + 1, s + 1 + n, x) - s;

        if (res <= n) cout << res << '\n';
        else cout << "-1\n";
    }
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