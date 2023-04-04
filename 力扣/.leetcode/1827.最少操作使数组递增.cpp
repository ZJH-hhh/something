/*
 * @lc app=leetcode.cn id=1827 lang=cpp
 *
 * [1827] 最少操作使数组递增
 */

// @lc code=start
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int res = 0, pre = nums[0];
        for (int i = 1; i < nums.size(); i ++ ) {
            int t = nums[i] - (pre + 1);
            if (t <= 0) {
                res += -t;
                pre = nums[i] - t;
            } else pre = nums[i];
        }
        return res;
    }
};
// @lc code=end

