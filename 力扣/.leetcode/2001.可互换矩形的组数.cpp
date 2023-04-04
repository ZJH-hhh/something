/*
 * @lc app=leetcode.cn id=2001 lang=cpp
 *
 * [2001] 可互换矩形的组数
 */

// @lc code=start
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

class Solution {
using ll = long long;
public:
    double eps = 1e-6;

    ll C(int n, int m) {
        if (n < m) return 0;
        if (n == m || m == 0) return 1;
        return C(n - 1, m - 1) + C(n - 1, m);
    }

    ll interchangeableRectangles(std::vector<std::vector<int>>& rectangles) {
        std::unordered_map<double, int> mp;
        for (auto& t: rectangles) {
            double ratio = t[0] * 1.0 / t[1];
            mp[ratio] ++ ;
        }
        ll res = 0;
        for (auto& [k, v]: mp) res += C(v, 2);
        return res;
    }
};
// @lc code=end

