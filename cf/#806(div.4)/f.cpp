#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<int> a, b;
    for (int i = 1; i <= n; i ++ ){
        int x;
        cin >> x;
        if (x < i){
            a.emplace_back(x);
            b.emplace_back(i);
        }
    }

    long long res = 0;
    for (auto &t: a)
        res += lower_bound(b.begin(), b.end(), t) - b.begin();
    
    cout << res << '\n';
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