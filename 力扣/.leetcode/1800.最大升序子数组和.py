#
# @lc app=leetcode.cn id=1800 lang=python3
#
# [1800] 最大升序子数组和
#

# @lc code=start
class Solution:
    def maxAscendingSum(self, nums: List[int]) -> int:
        i, res = 0, 0
        while i < len(nums):
            sum = nums[i]
            i += 1
            while i < len(nums) and nums[i] > nums[i - 1]:
                sum += nums[i]
                i += 1
            res = max(res, sum)

        return res

# @lc code=end

