#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

typedef long long ll;

const int N = 5005;

int n;
int p[N], tr[N];
int pre[N][N]; // pre[i][j]表示前i个数中小于等于j的数的个数

// int lowbit(int x){
//     return x & -x;
// }

// void update(int x, int c){
//     for (int i = x; i <= n; i += lowbit(i)) tr[i] += c;
// }

// int sum(int x){
//     int res = 0;
//     for (int i = x; i; i -= lowbit(i)) res += tr[i];
//     return res;
// }

void solve(){
    cin >> n;
    for (int i = 1; i <= n; i ++ ) cin >> p[i];

    for (int i = 1; i <= n; i ++ ) for (int j = 1; j <= n; j ++ ) pre[i][j] = 0; // 初始化为0

    for (int i = 1; i <= n; i ++ ){
        for (int j = 1; j <= n; j ++ )
            pre[i][j] += pre[i - 1][j];
        for (int j = p[i]; j <= n; j ++ )
            pre[i][j] ++ ;
    }

    // 枚举b,c, 计算前b-1个数中，小于p[c]的个数，即为a的选法
    // 然后计算后n-c个数中，小于等于p[b]的数量，即为d的选法
    // 根据乘法原理可得答案
    ll res = 0;
    for (int b = 1; b <= n - 2; b ++ )
        for (int c = b + 1; c <= n - 1; c ++ )
            res += pre[b - 1][p[c] - 1] * (p[b] - pre[c][p[b]]);

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