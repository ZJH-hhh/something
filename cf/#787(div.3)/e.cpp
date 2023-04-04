#include <iostream>
#include <algorithm>

using namespace std;

void solve() {
    int n, k;
    string s;
    cin >> n >> k;
    cin >> s;
    int mx = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] - 'a' > k) {
            char L = s[i] - (k - mx);
            char R = s[i];
            for (int j = 0; j < n; j++)if (L <= s[j] && s[j] <= R)s[j] = L;
            break;
        }
        mx = max(mx, s[i] - 'a');
    }
    for (int i = 0; i < n; i++)if (s[i] <= 'a' + mx)s[i] = 'a';
    cout << s << endl;
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