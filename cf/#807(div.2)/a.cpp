#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 205;

int a[N];

void solve(){
    int n, x;
    cin >> n >> x;
    for (int i = 0; i < n * 2; i ++ ) cin >> a[i];

    sort(a, a + n * 2);

    bool flag = true;
    for (int i = 0; i < n; i ++ )
        if (a[i] + x > a[n + i]){
            flag = false;
            break;
        }

    if (flag) cout << "YES\n";
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