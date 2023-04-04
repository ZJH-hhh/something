#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>

using namespace std;

typedef long long ll;

const int N = 1e5 + 5;

int n;
int c[N];
map<int, int> mp;
map<int, int> res;

void solve(){
    cin >> n;
    mp.clear();
    res.clear();

    for (int i = 1; i <= n; i ++ ){
        cin >> c[i];
        if (!res.count(c[i])) res[c[i]] = 1;
        if (mp[c[i]])
            if ((i - mp[c[i]] + 1) % 2 == 0) res[c[i]] ++ ;
        mp[c[i]] = i;
    }

    for (int i = 1; i <= n; i ++ ){
        if (res.count(i)) cout << res[i] << ' ';
        else cout << "0 ";
    }
    cout << '\n';
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