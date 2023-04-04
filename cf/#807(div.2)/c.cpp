#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

void solve(){
    ll n, m, q;
    string s;
    cin >> n >> m >> q >> s;
    s = '0' + s;

    vector<pll> v;
    vector<ll> len;
    v.emplace_back(1, n);
    len.push_back(n);

    ll slen = n;
    for (int i = 0; i < m; i ++ ){
        ll l, r;
        cin >> l >> r;
        slen += r - l + 1;
        v.emplace_back(l, r);
        len.emplace_back(slen);
    }

    while (q -- ){
        ll k; 
        cin >> k;
        while (k > n){
            ll p = lower_bound(len.begin(), len.end(), k) - len.begin();
            k = v[p].second - (len[p] - k);
        }
        cout << s[k] << '\n';
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