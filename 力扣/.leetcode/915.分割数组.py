#
# @lc app=leetcode.cn id=915 lang=python3
#
# [915] 分割数组
#

# @lc code=start
class Solution:
    def partitionDisjoint(self, nums: List[int]) -> int:
        n = len(nums)
        minv, maxv = [nums[n - 1]] * n, [nums[0]] * n
        i = 0
        while i < n:
            maxv[i] = max(maxv[i - 1], nums[i])
            i += 1
        
        i = n - 2
        while i >= 0:
            minv[i] = min(minv[i + 1], nums[i])
            i -= 1
        
        l = 0
        while maxv[l] > minv[l + 1]:
            l += 1
        
        return l + 1
# @lc code=end

