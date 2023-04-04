#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

void solve(){
    string s;
    cin >> s;
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    if (s == "yes") cout << "YES\n";
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