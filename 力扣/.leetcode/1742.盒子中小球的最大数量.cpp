/*
 * @lc app=leetcode.cn id=1742 lang=cpp
 *
 * [1742] 盒子中小球的最大数量
 */

// @lc code=start
#include <unordered_map>
#include <iostream>
#include <algorithm>

class Solution {
public:
    int countBalls(int lo, int hi) {
        std::unordered_map<int, int> mp;
        for (int i = lo; i <= hi; i ++ ) {
            int x = i, t = 0;
            while (x) {
                t += x % 10;
                x /= 10;
            }
            mp[t] ++ ;
        }
        
        int res = -1;
        for (auto& [k, v]: mp) {
            res = std::max(res, v);
        }
        return res;
    }
};
// @lc code=end

