#include <iostream>
#include <algorithm>
#include <cstring>
#include <set>

using namespace std;

const int N = 1e5 + 5;
string s[N];

void solve(){
    int n;
    cin >> n;

    set<string> st;
    for (int i = 0; i < n; i ++ ){
        cin >> s[i];
        st.insert(s[i]);
    }

    for (int i = 0; i < n; i ++ ){
        string str = s[i];
        bool flag = false;
        for (int j = 0; j < str.size(); j ++ ){
            string s1 = str.substr(0, j);
            string s2 = str.substr(j);
            if (st.count(s1) && st.count(s2)){
                flag = true;
                break;
            }
        }
        if (flag) cout << 1;
        else cout << 0;
    }

    cout << '\n';  
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