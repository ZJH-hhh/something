#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 105;

int a[N];

void solve(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i ++ ) cin >> a[i];
    for (int i = 0; i < n; i ++ ){
        int m;
        string s;
        cin >> m >> s;
        for (int j = 0; j < m; j ++ )
            if (s[j] == 'U'){
                a[i] -- ;
                if (a[i] < 0) a[i] = 9;
            }
            else {
                a[i] ++ ;
                if (a[i] > 9) a[i] = 0;
            }
    }

    for (int i = 0; i < n; i ++ ) cout << a[i] << ' ';
    cout << '\n';
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