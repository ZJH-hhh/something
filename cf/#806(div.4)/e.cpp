#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>

using namespace std;

const int N = 105;

string s[N];

void solve(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i ++ ) cin >> s[i];
    
    if (n == 1){
        cout << "0\n";
        return ;
    }

    int res = 0;
    for (int i = 0; i < n; i ++ )
        for (int j = 0; j < n; j ++ ){
            int cnt = s[i][j] - '0' + s[j][n - i - 1] - '0' + s[n - j - 1][i] - '0' + s[n - i - 1][n - j - 1] - '0';
            res += min(cnt, 4 - cnt);
        }

    cout << res / 4 << '\n';
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