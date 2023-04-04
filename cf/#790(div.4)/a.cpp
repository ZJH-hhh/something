#include <iostream>
#include <algorithm>

using namespace std;

void solve(){
    string s;
    cin >> s;

    if (s[0] + s[1] + s[2] == s[3] + s[4] + s[5]) cout << "YES\n";
    else cout << "NO\n";
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