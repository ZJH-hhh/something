/*
 * @lc app=leetcode.cn id=1911 lang=cpp
 *
 * [1911] 最大子序列交替和
 */

// @lc code=start
class Solution {
public:
    long long maxAlternatingSum(std::vector<int>& nums) {
        long long res = 0;
        int pre = 0;
        for (auto& num: nums) {
            if (num > pre) res += num - pre;
            pre = num; 
        }
        return res;
    }
};
// @lc code=end

