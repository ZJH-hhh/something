#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

const int N = 1e5 + 5, mod = 1e9 + 7;

int n;
int a[N], b[N], c[N];
int p[N];

int find(int x){
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int qmi(int a, int b, int p){
    int res = 1 % p;
    while (b){
        if (b & 1) res = (ll)res * a % p;
        a = (ll)a * a % p;
        b >>= 1;
    }
    return res;
}

void solve(){
    cin >> n;
    for (int i = 0; i < n; i ++ ) cin >> a[i];
    for (int i = 0; i < n; i ++ ) cin >> b[i];
    for (int i = 0; i < n; i ++ ) cin >> c[i];

    for (int i = 1; i <= n; i ++ ) p[i] = i;
    for (int i = 0; i < n; i ++ ){
        if (a[i] == b[i]) p[a[i]] = 0;
        p[find(a[i])] = find(b[i]);
    }

    for (int i = 0; i < n; i ++ ) p[find(c[i])] = 0;

    int cnt = 0;
    for (int i = 1; i <= n; i ++ ) cnt += (p[i] == i);

    cout << qmi(2, cnt, mod) << endl;
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