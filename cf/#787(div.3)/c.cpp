#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long ll;

const int N = 35;

ll a[N];

void solve(){
    string s;
    cin >> s;

    if (s.size() == 1){
        cout << "1\n";
        return ;
    }

    int l = 0, r = s.size() - 1;
    while (s[l] != '0' && l < s.size()) l ++ ;
    while (s[r] != '1' && r >= 0) r -- ;

    int res = l - r + 1;
    if (l >= s.size()) res -- ;
    if (r < 0) res -- ;

    cout << res << endl;
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