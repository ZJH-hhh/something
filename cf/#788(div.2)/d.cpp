#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

const int N = 38731;

ll f[N];

void init(){
    f[1] = 0, f[2] = 2, f[3] = 6;
    int cnt[3] = {1, 1, 1};

    for (int i = 4; i <= N; i ++ ){
        int t = i % 3;
        f[i] = f[i - 1];
        for (int j = 0; j < 3; j ++ ) 
            if (j != t) f[i] += 2 * cnt[j];
        cnt[t] ++ ;
    }
}

void solve(){
    int n;
    cin >> n;
    cout << lower_bound(f + 1, f + N + 1, n) - f << '\n';
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