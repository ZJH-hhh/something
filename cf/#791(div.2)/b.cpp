#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

typedef long long ll;

const int N = 2e5 + 5;

ll n, m;
map<int, int> a;

void solve(){
    cin >> n >> m;

    ll sum = 0;
    for (int i = 1; i <= n; i ++ ){
        int x;
        cin >> x;
        a[i] = x;
        sum += x;
    }

    int same = 0;
    while (m -- ){
        int op, pos, x;
        cin >> op;
        if (op == 1){
            cin >> pos >> x;
            if (a.count(pos)) sum += x - a[pos];
            else sum += x - same;
            a[pos] = x;
        }
        else {
            cin >> x;
            sum = 1ll * x * n;
            same = x;
            a.clear();
        }
        cout << sum << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t -- ) solve();

    return 0;
}