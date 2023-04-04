/*
 * @lc app=leetcode.cn id=164 lang=cpp
 *
 * [164] 最大间距
 */

// @lc code=start
#include <iostream>
#include <algorithm>
#include <vector>

class Solution {
public:
    int maximumGap(std::vector<int>& nums) {
        if (nums.size() < 2) return 0;
        std::sort(nums.begin(), nums.end());

        int res = 0;
        for (int i = 1; i < nums.size(); i ++ )
            res = std::max(res, nums[i] - nums[i - 1]);

        return res;
    }
};
// @lc code=end

