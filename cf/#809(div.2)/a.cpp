#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long ll;

const int N = 2e5 + 5;

bool st[N];

void solve(){
    int n, m;
    cin >> n >> m;
    string s(m + 1, 'B');
   
    memset(st, false, sizeof st);
    while (n -- ){
        int x;
        cin >> x;
        int a = min(x, m + 1 - x);
        int b = max(x, m + 1 - x); 
        if (!st[a]) s[a] = 'A', st[a] = true;
        else s[b] = 'A', st[b] = true; 
    }
    cout << s.substr(1) << '\n';
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