#
# @lc app=leetcode.cn id=1695 lang=python3
#
# [1695] 删除子数组的最大得分
#

# @lc code=start
class Solution:
    def maximumUniqueSubarray(self, nums: List[int]) -> int:
        n = len(nums)
        s = [0] * (n + 1)
        nums = [0] + nums
        for i in range(1, n + 1):
            s[i] = s[i - 1] + nums[i]

        digits = [0] * (10 ** 4 + 5)

        res = 0
        l = r = 1
        for r in range(n + 1):
            digits[nums[r]] += 1
            while l <= n and digits[nums[r]] > 1:
                digits[nums[l]] -= 1
                l += 1
            res = max(res, s[r] - s[l - 1])
        
        return res

# @lc code=end

