#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 200010;

int a[N];

void solve(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i ++ ) cin >> a[i];

    for (int i = n - 1; i > 0; i -= 2)
        if (a[i] < a[i - 1]) swap(a[i], a[i - 1]);

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