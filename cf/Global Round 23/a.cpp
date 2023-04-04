#include <iostream>
#include <cstring>
#include <unordered_map>

using namespace std;

constexpr int N = 2e5 + 5;

int n, m;
int a[N];

void solve() {
    cin >> n >> m;
    bool flag = false;
    for (int i = 0; i < n; i ++ ) {
        int x;
        cin >> x;
        if (x) flag = true;
    }
    puts(flag && n >= m ? "YES" : "NO");
}

int main() {
    int t = 1;
    cin >> t;
    while (t -- ) solve();
    return 0;
}