#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

const int N = 110;

int b[N], d[N];

void solve(){
    int n;
    cin >> n;

    unordered_map<int, int> mp;

    for (int i = 0; i < n; i ++ ){
        cin >> b[i] >> d[i];
        mp[d[i]] = max(mp[d[i]], b[i]);
    }

    if (mp.size() < 10){
        cout << "MOREPROBLEMS\n";
        return ;
    }

    int res = 0;
    for (auto [d, b] : mp) res += b;

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