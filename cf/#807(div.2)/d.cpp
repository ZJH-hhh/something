#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

typedef long long ll;

const int N = 2e5 + 5;

void solve(){
    int n;
    string s1, s2;
    cin >> n >> s1 >> s2;

    if (s1[0] != s2[0]){
        cout << "-1\n";
        return ;
    }

    vector<int> a, b;
    for (int i = 1; i < s1.size(); i ++ ){
        if (s1[i] != s1[i - 1]) a.emplace_back(i);
        if (s2[i] != s2[i - 1]) b.emplace_back(i);
    }

    if (a.size() != b.size()){
        cout << "-1\n";
        return ;
    }
 
    ll res = 0;
    for (int i = 0; i < a.size(); i ++ )
        res += abs(a[i] - b[i]);
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