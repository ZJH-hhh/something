#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>

using namespace std;

constexpr int N = 2e5 + 5;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    if (a == b + c || b == a + c || c == a + b) puts("YES");
    else puts("NO");
}

int main() {
    int t = 1;
    cin >> t;
    while (t -- ) solve();
    return 0;
}