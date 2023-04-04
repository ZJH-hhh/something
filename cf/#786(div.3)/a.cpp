#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int qmi(int a, int b){
    int res = 1;
    while (b){
        if (b & 1) res *= a;
        a *= a;
        b >>= 1;
    }

    return res;
}

void solve(){
    int x, y;
    cin >> x >> y;

    if (y % x){
        cout << "0 0\n";
        return ;
    }

    int div = y / x;
    for (int i = 1; i <= div; i ++ )
        for (int j = 1; j <= div; j ++ )
            if (qmi(i, j) == div){
                cout << j << ' ' << i << '\n';
                return ;
            }
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