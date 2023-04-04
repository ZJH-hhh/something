#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e5 + 5;

int n;
int a[N];

void print(){
    for (int i = 1; i <= n; i ++ ) cout << a[i] << ' ';
    cout << endl;
}

void solve(){
    cin >> n;

    int cnt = 0;
    for (int i = 0; i < n; i ++ ){
        cin >> a[i];
        cnt += (a[i] < 0);
    } 

    for (int i = 0; i < cnt; i ++ ) a[i] = -abs(a[i]);
    for (int i = cnt;  i < n; i ++ ) a[i] = abs(a[i]);

    // print();

    if (is_sorted(a, a + n)) cout << "YES\n";
    else cout << "NO\n";
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