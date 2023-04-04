#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

void solve(){
    int n;
    cin >> n;

    int res = (1 << 30) - 1;
    for (int i = 0; i < n; i ++ ){
        int x;
        cin >>  x;
        if (x != i) res &= x;
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