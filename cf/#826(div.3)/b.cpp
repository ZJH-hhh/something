#include <iostream>
#include <algorithm>
#include <cstring>
#include <unordered_map>

using namespace std;

constexpr int N = 2e5 + 5;

void solve() {
    int n;
    cin >> n;
    if (n == 1 || n == 3) {
        puts("-1");
        return ;
    }
    if (n % 2 == 0) {
        for (int i = n; i >= 1; i -- ) cout << i << ' ';
    }
    else {
        cout << n - 1 << ' ' << n << ' ';
        for (int i = 1; i <= n - 2; i ++ ) cout << i << ' ';
    }
    puts("");
}

int main() {
    int t;
    cin >> t;
    while (t -- ) solve();
    return 0;
}