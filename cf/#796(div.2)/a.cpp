#include <iostream>
#include <algorithm>

using namespace std;

void solve(){
    int x;
    cin >> x;
    int res = x & -x;
    if (res == x) res ++ ;
    if (x == 1) res = 3;
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