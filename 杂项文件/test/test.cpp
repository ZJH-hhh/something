#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long ll;

const int N = 200010;

void solve(){
    string s;
    cin >> s;

    for (int i = 0; i < s.size(); i ++ ){
        int lena = 0, lenb = 0;
        while (s[i] == 'a') lena ++ , i ++ ;
        while (s[i] == 'b') lenb ++ , i ++ ;

        if (lena == 1 || lenb == 1){
            cout << "NO\n";
            return ;
        }
    }

    cout << "YES\n";
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