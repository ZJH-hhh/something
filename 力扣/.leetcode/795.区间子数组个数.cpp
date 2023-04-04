/*
 * @lc app=leetcode.cn id=795 lang=cpp
 *
 * [795] 区间子数组个数
 */

// @lc code=start
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

class Solution {
public:
    int numSubarrayBoundedMax(std::vector<int>& nums, int left, int right) {
        int res = 0;
        int l = -1, r = -1;
        for (int i = 0; i < nums.size(); i ++ ) {
            if (nums[i] > right) l = i;
            if (nums[i] >= left) r = i;
            res += r - l;
        }
        return res;
    }
};
// @lc code=end

