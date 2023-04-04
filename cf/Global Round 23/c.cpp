#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

using pii = pair<int, int>;

constexpr int N = 2e5 + 5;

int n;
int a[N];
pii d[N];

void solve() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        d[i] = {a[i] - a[i - 1], i};
    }
    sort(d + 1, d + n + 1);
    for(int i = n; i >= 1; i--)
        cout << d[i].second << " \n"[i == 1];
}

int main() {
    int t = 1;
    cin >> t;
    while (t -- ) solve();
    return 0;
}