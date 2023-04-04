#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>

using namespace std;

void solve(){
    int n;
    string s;
    cin >> n >> s;

    map<char, bool> mp;
    int res = 0;
    for (int i = 0; i < n; i ++ ) {
        if (!mp[s[i]]) {
            res += 2;
            mp[s[i]] = true;
        }
        else res ++ ;
    }

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