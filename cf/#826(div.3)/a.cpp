#include <iostream>
#include <algorithm>
#include <cstring>
#include <unordered_map>

using namespace std;

constexpr int N = 2e5 + 5;

unordered_map<char, int> mp = {{'S', 0}, {'M', 1}, {'L', 2}};

void solve() {
    string a, b;
    cin >> a >> b;
    if (a == b) cout << "=\n";
    else {
        char c1 = a[a.size() - 1], c2 = b[b.size() - 1];
        if (c1 == c2 && c1 == 'S') {
            if (a.size() > b.size())
                cout << "<\n";
            else cout << ">\n";
            return ;
        }

        if (c1 == c2 && c1 == 'L') {
            if (a.size() > b.size())
                cout << ">\n";
            else cout << "<\n";
            return ;
        }

        if (mp[c1] > mp[c2]) cout << ">\n";
        else cout << "<\n";
    }
}

int main() {
    int t;
    cin >> t;
    while (t -- ) solve();
    return 0;
}