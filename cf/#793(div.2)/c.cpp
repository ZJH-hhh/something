#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

void solve(){
    int n;
    cin >> n;
    
    map<int, int> mp;
    int res = 0;
    while (n -- ){
        int x;
        cin >> x;
        mp[x] ++ ;
        if (mp[x] <= 2) res ++ ;
    }

    cout << (res + 1 >> 1) << '\n';
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