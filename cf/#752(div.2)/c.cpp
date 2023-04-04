#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

typedef long long ll;

const int N = 40010, mod = 1e9 + 7;

int f[N];
vector<int> a;

void init(){
    for (int i = 1; i <= N; i ++ ){
        string s = to_string(i);
        string t = s;
        reverse(t.begin(), t.end());
        if (s == t) a.push_back(i);
    }

    f[0] = 1;
    for (int i = 0; i < a.size(); i ++ )
        for (int j = a[i]; j <= N; j ++ )
            f[j] = (f[j] + f[j - a[i]]) % mod;
}

void solve(){
    int n;
    cin >> n;
    cout << f[n] << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    init();

    int t = 1;
    cin >> t;
    while (t -- ) solve();

    return 0;
}