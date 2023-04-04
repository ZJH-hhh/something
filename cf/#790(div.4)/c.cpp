#include <iostream>
#include <algorithm>

using namespace std;

const int N = 55;

string str[N];

void solve(){
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i ++ ) cin >> str[i];

    int res = 1e9;
    for (int i = 0; i < n; i ++ )
        for (int j = i + 1; j < n; j ++ ){
            string s1 = str[i], s2 = str[j];
            int cnt = 0;
            for (int k = 0; k < m; k ++ ) cnt += abs(s2[k] - s1[k]);
            res = min(res, cnt);
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