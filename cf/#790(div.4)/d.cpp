#include <iostream>
#include <algorithm>

using namespace std;

const int N = 205;

int n, m;
int g[N][N];
int dx[5] = {-1, -1, 1, 1}, dy[5] = {-1, 1, -1, 1};

int get(int x, int y){
    int sum = 0;
    for (int i = 0; i < 4; i ++ )       
        for (int k = 1; k <= min(n, m); k ++ ){
            int a = x + dx[i] * k, b = y + dy[i] * k;
            if (a >= 0 && a < n && b >= 0 && b < m) sum += g[a][b];
        }

    return sum;
}

void solve(){
    cin >> n >> m;

    for (int i = 0; i < n; i ++ )
        for (int j = 0; j < m; j ++ ) 
            cin >> g[i][j];

    int res = 0;
    for (int i = 0; i < n; i ++ )
        for (int j = 0; j < m; j ++ )
            res = max(res, g[i][j] + get(i, j));
        
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