#include <iostream>
#include <algorithm>

using namespace std;

void solve(){
    int n;
    cin >> n;

    int odd = 0, minv = 1e9;
    for (int i = 0; i < n; i ++ ){
        int x;
        cin >> x;
        odd += x & 1;
        minv = min(minv, __lg(x & -x));
    }
    
    if (odd) cout << n - odd << '\n';
    else cout << minv + n - odd - 1 << '\n';
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