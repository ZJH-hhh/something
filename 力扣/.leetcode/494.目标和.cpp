/*
 * @lc app=leetcode.cn id=494 lang=cpp
 *
 * [494] 目标和
 */

// @lc code=start
#include <iostream>
#include <algorithm>
#include <vector>

class Solution {
public:
    int res = 0;
    int n = 0;

    int findTargetSumWays(std::vector<int>& nums, int target) {
        n = nums.size();
        dfs(0, 0, target, nums);
        return res;
    }

    void dfs(int u, int sum, int target, std::vector<int>& nums) {
        if (u == n) {
            res += sum == target;
            return ;
        }
        dfs(u + 1, sum + nums[u], target, nums);
        dfs(u + 1, sum - nums[u], target, nums);
    }
};
// @lc code=end

