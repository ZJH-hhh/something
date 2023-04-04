#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_set>

using namespace std;

constexpr int N = 2e5 + 5;

void solve() {
    char res = 'B';
    for (int i = 0; i < 8; i ++ ) {
        string s;
        cin >> s;
        if (s == "RRRRRRRR") res = 'R';
    }
    cout << res << '\n';
}

int main() {
    int t = 1;
    cin >> t;
    while (t -- ) solve();
    return 0;
}