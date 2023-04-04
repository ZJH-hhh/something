#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

const int N = 105;

int a[N];

void solve(){
    int n;
    cin >> n;

    int cnt = 0;
    unordered_map<int, int> mp;
    for (int i = 1; i <= n; i ++ ){
        int x;
        cin >> x;
        cnt += (x == 0);
        mp[x] ++ ;
    } 

    if (cnt) cout << n - cnt << '\n';
    else if (mp.size() == n) cout << n + 1<< '\n';
    else cout << n << '\n';
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