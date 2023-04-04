#include <iostream>
#include <algorithm>
#include <cstring>
#include <unordered_map>

using namespace std;

unordered_map<string, int> mp;
int idx;

void init(){
    for (char a = 'a'; a <= 'z'; a ++ )
        for (char b = 'a'; b <= 'z'; b ++ )
            if (a != b){
                string s;
                s += a;
                s += b;
                mp[s] = ++ idx;
            }
}

void solve(){
    string s;
    cin >> s;
    cout << mp[s] << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    init();

    int t = 1;
    cin >> t;
    while (t -- ) solve();

    return 0;
}