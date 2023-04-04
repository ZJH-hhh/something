#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>

using namespace std;

constexpr int N = 2e5 + 5;

void solve() {
    unordered_map<char, int> S, T;
    S['a'] ++ , T['a'] ++ ;
    int n;
    cin >> n;
    long long cnts = 0, cntt = 0;
    while (n -- ) {
        int op, k;
        string s;
        cin >> op >> k >> s;
        if (op == 1) {
            for (auto& c: s) S[c] += k;
            cnts += k * s.size();
        }
        else {
            for (auto& c: s) T[c] += k;
            cntt += k * s.size();
        }
        
        bool flag = false;
        for (char ch = 'b'; ch <= 'z'; ch ++ )
            if (T.count(ch)) {
                puts("YES");
                flag = true;
                break;
            }
        
        if (!flag) {
            for (char ch = 'b'; ch <= 'z'; ch ++ ) 
                if (S.count(ch))
                    flag = true;
            if (!flag && cnts < cntt) puts("YES");
            else puts("NO");
        }
    }
}

int main() {
    int t = 1;
    cin >> t;
    while (t -- ) solve();
    return 0;
}