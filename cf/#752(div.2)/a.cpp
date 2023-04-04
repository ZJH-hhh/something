#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

void solve(){
    string s;
    cin >> s;
    int len = s.size();

    if (len == 1) cout << "Bob ";
    else cout << "Alice ";

    int a = 0;
    for (int i = 0; i < len; i ++ )
        a += s[i] - 'a' + 1;

    if (len == 1){
        cout << a << '\n';
        return ;
    }

    if (len & 1){
        if (s[0] > s[len - 1]){
            int b = s[len - 1] - 'a' + 1;
            a -= b;
            cout << a - b << '\n';
        }
        else {
            int b = s[0] - 'a' + 1;
            a -= b;
            cout << a - b << '\n';
        }
        return ;
    }
    
    cout << a << '\n';
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