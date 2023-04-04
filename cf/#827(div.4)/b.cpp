#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_set>
 
using namespace std;
 
constexpr int N = 2e5 + 5;
 
void solve() {
    int n;
    cin >> n;
    unordered_set<int> S;
    string res = "YES";
    for (int i = 0; i < n; i ++ ) {
        int x;
        cin >> x;
        if (S.count(x)) res = "NO";
        S.insert(x);
    }
    cout << res << "\n";
}
 
int main() {
    int t = 1;
    cin >> t;
    while (t -- ) solve();
    return 0;
}