#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

void solve(){
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    if (a + b + c >= x + y && a + c >= x && b + c >= y) cout << "YES\n";
    else cout << "NO\n";
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