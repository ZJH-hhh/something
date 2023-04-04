#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int dgt(int x){
    int res = 0;
    while (x) res ++ , x /= 10;
    return res;
}

int count(int n, int x){
    int res = 0, m = dgt(n);
    for (int i = 1; i <= m; i ++ ){
        int p = pow(10, i - 1);
        int l = n / p / 10, r = n % p, di = n / p % 10;
        
        printf("p=%d l=%d r=%d ", p, l, r);
        
        if (x) res += l * p;
        else if (l) res += (l - 1) * p;
        
        printf("res=%d ", res);
        
        if (x < di && (x || l)) res += p;
        if (x == di && (x || l)) res += r + 1;
        
        printf("res=%d\n", res);
    }
    
    return res;
}

int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(0), cout.tie(0);
    
    int a, b;
    while (cin >> a >> b, a || b){
        if (a > b) swap(a, b);
        for (int i = 1; i < 2; i ++ )
            cout << count(b, i) - count(a - 1, i) << ' ';
        cout << '\n';
    }
    
    return 0;
}