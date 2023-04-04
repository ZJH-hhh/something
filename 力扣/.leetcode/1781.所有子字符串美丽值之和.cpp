/*
 * @lc app=leetcode.cn id=1781 lang=cpp
 *
 * [1781] 所有子字符串美丽值之和
 */

// @lc code=start
#include <iostream>
#include <algorithm>
#include <unordered_map>

class Solution {
public:
    int beautySum(std::string s) {
        int res = 0, n = s.size();
        for (int i = 0; i < n; i ++ ) {
            std::unordered_map<char, int> cnt;
            int maxv = -1;
            for (int j = i; j < n; j ++ ) {
                cnt[s[j]] ++ ;
                maxv = std::max(maxv, cnt[s[j]]);
                int minv = 505;
                for (auto& [k, v]: cnt) minv = std::min(minv, v);
                res += maxv - minv;
            }
        }
        return res;
    }
};
// @lc code=end

