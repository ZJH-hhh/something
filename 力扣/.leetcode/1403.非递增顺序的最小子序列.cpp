/*
 * @lc app=leetcode.cn id=1403 lang=cpp
 *
 * [1403] 非递增顺序的最小子序列
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<int> minSubsequence(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end(), [&](int a, int b) {
            return a > b;
        });
        
        int sum = 0;
        for (auto& num: nums) sum += num;

        std::vector<int> res;
        int tmp = 0;
        for (auto& num: nums) {
            tmp += num;
            res.emplace_back(num);
            if (tmp > sum - tmp) break;
        }

        return res;
    }
};
// @lc code=end

