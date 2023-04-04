#include <iostream>
#include <cstring>
#include <unordered_map>

using namespace std;

constexpr int N = 2e5 + 5;

int n;
int a[N];

void solve() {
    cin >> n;
    for (int i = 0; i < n; i ++ ) cin >> a[i];
    int l = 0, r = n - 1;
    int res = 0;
    while (l < r) {
        while (a[l] == 0) l ++ ;
        while (a[r] == 1) r -- ;
        if (l < r) {
            swap(a[l], a[r]);
            res ++ ;
        }
    }
    cout << res << '\n';
}

int main() {
    int t = 1;
    cin >> t;
    while (t -- ) solve();
    return 0;
}