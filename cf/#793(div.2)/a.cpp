#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>

using namespace std;

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;

    map<char, int> mp;
    for (int i = 0; i < n; i ++ ) mp[s[i]] ++ ;
    if (mp.size() == 1){
        cout << n << '\n';
        return ;
    }

    int res = 0;
    char ch = s[n / 2];
    for (int i = n / 2; s[i] == s[n / 2]; i -- ) res ++ ;
    for (int i = n / 2  + 1; s[i] == s[n / 2]; i ++ ) res ++ ;

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