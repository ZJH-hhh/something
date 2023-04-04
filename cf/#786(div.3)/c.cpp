#include <iostream>
#include <algorithm>
#include <cstring>
#include <unordered_map>

using namespace std;

typedef long long ll;

const int N = 55;

ll c[N][N];

void init(){
    for (int i = 0; i < N; i ++ )
        for (int j = 0; j <= i; j ++ )
            if (!j) c[i][j] = 1;
            else c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]);
}

void solve(){
    string s, p;
    cin >> s >> p;
    
    for (auto c : p)
        if (c == 'a'){
            if (p.size() == 1) cout << "1\n";
            else cout << "-1\n";
            return ;
        }
    
    ll res = 0;
    int len = s.size();
    for (int i = 0; i <= len; i ++ ) res += c[len][i];

    cout << res << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    init();

    int t = 1;
    cin >> t;
    while (t -- ) solve();

    return 0;
}