#
# @lc app=leetcode.cn id=410 lang=python3
#
# [410] 分割数组的最大值
#

# @lc code=start
class Solution:
    def splitArray(self, nums: List[int], k: int) -> int:
        l, r = max(nums), sum(nums)

        def check(m):
            cnt = sum = 0
            for i, x in enumerate(nums):
                if sum + x > m:
                    cnt += 1
                    sum = 0
                sum += x
            if sum: cnt += 1
            return cnt <= k

        while l < r:
            mid = l + r >> 1
            if check(mid): r = mid
            else: l = mid + 1
        return l
# @lc code=end

