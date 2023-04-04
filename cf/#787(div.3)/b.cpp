#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long ll;

const int N = 35;

ll a[N];

void solve(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++ ) cin >> a[i];

    if (n == 1){
        cout << "0\n";
        return ;
    }

    if (a[n] == 1){
        cout << "-1\n";
        return ;
    }
    
    for (int i = 1; i <= n; i ++ )
        if (a[i] == 0 && i > 1){
            cout << "-1\n";
            return ;
        }

    ll res = 0;
    for (int i = n - 1; i > 0; i -- )
        while (a[i] >= a[i + 1]){
            a[i] /= 2;
            if (a[i] == 0 && i > 1){
                cout << "-1\n";
                return ;
            }
            res ++ ;
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