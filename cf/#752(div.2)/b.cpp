#include <iostream>
#include <algorithm>
#include <cstring>
#include <unordered_map>

using namespace std;

void solve(){
    string s;
    cin >> s;
    
    unordered_map<char, int> mp;
    int loop = 0;
    for (auto c : s){
        if (mp[c]) break;
        loop ++ ;
        mp[c] ++ ;
    }

    for (int i = loop; i < s.size(); i ++ )
        if (s[i] != s[i - loop]){
            cout << "NO\n";
            return ;
        }
    
    cout << "YES\n";
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