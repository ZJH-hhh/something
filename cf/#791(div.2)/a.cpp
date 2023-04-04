#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

void solve(){
    ll n;
    cin >> n;

    if (n < 4 || n & 1){
        cout << "-1\n";
        return ;
    }

    if (n <= 6){
        cout << 1 << ' ' << 1 << '\n';
        return ;
    }

    ll a = n / 6, b = n / 4;
    if (n % 6) a ++ ;

    if (a > b) a = b;

    cout << a << ' ' << b << '\n';
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