#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long ll;

void solve(){
    int n;
    cin >> n;

    int cnt = 0;
    bool flag = false;
    ll res = 0;
    for (int i = 0; i < n - 1; i ++ ){
        int x;
        cin >> x;
        if (x){
            res += x;
            flag = true;
        }
        else if (flag) cnt ++ ;
    }
    
    int x; cin >> x;
    
    cout << res + cnt << '\n';
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