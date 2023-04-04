#
# @lc app=leetcode.cn id=907 lang=python3
#
# [907] 子数组的最小值之和
#

"""

"""

# @lc code=start
class Solution:
    def sumSubarrayMins(self, arr: List[int]) -> int:
        arr = [float('-inf')] + arr + [float('-inf')]
        stk = []
        res = 0

        for i, x in enumerate(arr):
            while stk and arr[stk[-1]] > x:
                pos = stk.pop()
                res += (pos - stk[-1]) * (i - pos) * arr[pos]
            stk.append(i)

        return res % (10 ** 9 + 7)


# @lc code=end

