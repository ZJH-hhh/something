#include <iostream>
#include <algorithm>

using namespace std;

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    
    int cnt = 0;
    for (int i = 0; i < s.size() - 1; i += 2){
        if (s[i] ^ s[i + 1]) {
            cnt ++ ;
            s[i] = s[i + 1] = '2';
        }
    }

    char last = '2';
    int res = 0;
    for (int i = 0; i < s.size(); i ++ ){
        if (s[i] == '2') continue;
        if (s[i] != last) last = s[i], res ++ ;
    }

    cout << cnt << ' '  << max(res, 1) << '\n';
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