#
# @lc app=leetcode.cn id=1283 lang=python3
#
# [1283] 使结果不超过阈值的最小除数
#

# @lc code=start
class Solution:
    def smallestDivisor(self, nums: List[int], threshold: int) -> int:
        nums.sort()
        l, r = 1, nums[-1]
        while l < r:
            mid = l + r >> 1
            s = 0
            for x in nums:
                s += ceil(x / mid)
            
            if s <= threshold: r = mid
            else: l = mid + 1

        return r

# @lc code=end

