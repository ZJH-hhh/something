#include <iostream>
#include <algorithm>

using namespace std;

const int N = 55;

int n;
int a[N];

void solve(){
    cin >> n;
    for (int i = 0; i < n; i ++ ) cin >> a[i];

    sort(a, a  + n);

    int res = 0;
    for (int i = 1; i < n; i ++ ) res += a[i] - a[0];

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