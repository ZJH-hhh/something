#
# @lc app=leetcode.cn id=1802 lang=python3
#
# [1802] 有界数组中指定下标处的最大值
#

# @lc code=start

class Solution:
    def maxValue(self, n: int, index: int, maxSum: int) -> int:
        res = 0
        l, r = 0, maxSum
        maxSum -= n

        def check(x):
            res = x * x
            if x > index: 
                res -= (1 + x - index - 1) * (x - index - 1) // 2
            if x > n - index: 
                res -=  ((x - (n - index - 1)) - 1) * (x - (n - index - 1)) // 2
            return res

        while l < r:
            mid = l + r + 1 >> 1
            if check(mid) <= maxSum: l = mid
            else: r = mid - 1 
        
        return l + 1
# @lc code=end

