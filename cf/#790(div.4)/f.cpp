#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
 
using namespace std;
 
void solve(){
    int n, k;
    cin >> n >> k;
 
    map<int, int> mp;
 
    for (int i = 0; i < n; i ++ ){
        int x;
        cin >> x;
        mp[x] ++ ;
    }
 
    vector<int> v;
    for (auto [x, cnt] : mp)
        if (cnt >= k) v.push_back(x);
        
    if (v.empty()){
        cout << "-1\n";
        return ;
    }
 
    sort(v.begin(), v.end());
 
    int l = 0, r = 0, res = 0, last = 0, tail = 0;
    for (int i = 0; i < v.size() - 1; i ++ ){
        if (v[i] + 1 == v[i + 1]) r ++ ;
        else {
            if (r - l > res){
                last = l, tail = r;
                res = r - l;
            }
            r = l = i + 1;
        }
    }
    
    if (r - l > res) last = l, tail = r; 
    cout << v[last] << ' ' << v[tail] << '\n';
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