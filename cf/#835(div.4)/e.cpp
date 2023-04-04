#include <iostream>
#include <algorithm>
#include <cstring>
#include <unordered_map>
#include <vector>

using ll = long long;

const int N = 2e5 + 5;

int n;
int a[N], tmp[N], nums[N];

ll merge_sort(int l, int r) {
    if (l >= r) return 0;
    int mid = l + r >> 1;
    ll res = merge_sort(l, mid) + merge_sort(mid + 1, r);

    int k = 0, i = l, j = mid + 1;
    while (i <= mid && j <= r) {
        if (a[i] <= a[j]) tmp[k ++ ] = a[i ++ ];
        else {
            tmp[k ++ ] = a[j ++ ];
            res += mid - i + 1;
        }
    }

    while (i <= mid) tmp[k ++ ] = a[i ++ ];
    while (j <= r) tmp[k ++ ] = a[j ++ ];

    for (int i = l, j = 0; i <= r; i ++ , j ++ ) a[i] = tmp[j];
    return res;
}

void solve() {
    std::cin >> n;
    for (int i = 0; i < n; i ++ ) std::cin >> nums[i];

    for (int i = 0; i < n; i ++ ) a[i] = nums[i];

    int zero = 0, one = n - 1;
    while (zero < n && a[zero] == 1) zero ++ ;
    while (one >= 0 && a[one] == 0) one -- ;

    ll res = merge_sort(0, n - 1);

    for (int i = 0; i < n; i ++ ) a[i] = nums[i];
    a[zero] = 1;
    res = std::max(res, merge_sort(0, n - 1));

    for (int i = 0; i < n; i ++ ) a[i] = nums[i];
    a[zero] = a[one] = 0;
    res = std::max(res, merge_sort(0, n - 1));

    std::cout << res << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);

    int t = 1;
    std::cin >> t;
    while (t -- ) solve();
    return 0;
}