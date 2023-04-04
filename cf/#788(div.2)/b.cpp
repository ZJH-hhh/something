#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <cstring>
#include <vector>

using namespace std;

bool st[26];

void solve(){
    int n, m;
    string s;
    vector<int> pos;

    cin >> n >> s >> m;

    memset(st, false, sizeof st);

    while (m -- ){
        char c;
        cin >> c;
        st[c - 'a'] = true;
    }

    pos.push_back(0);
    for (int i = 0; i < s.size(); i ++ )
        if (st[s[i] - 'a']) pos.push_back(i);

    int res = 0;
    for (int i = 1; i < pos.size(); i ++ )
        res = max(res, pos[i] - pos[i - 1]);

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