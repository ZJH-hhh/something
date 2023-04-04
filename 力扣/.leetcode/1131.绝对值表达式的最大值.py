#
# @lc app=leetcode.cn id=1131 lang=python3
#
# [1131] 绝对值表达式的最大值
#

# @lc code=start
class Solution:
    def maxAbsValExpr(self, arr1: List[int], arr2: List[int]) -> int:
        a = [-10**7, 10 ** 7]
        b, c, d = a.copy(), a.copy(), a.copy()

        for i, (x, y) in enumerate(zip(arr1, arr2)):
            a[0] = max(a[0], x + y + i)
            a[1] = min(a[1], x + y + i)
            b[0] = max(b[0], x + y - i)
            b[1] = min(b[1], x + y - i)
            c[0] = max(c[0], x - y + i)
            c[1] = min(c[1], x - y + i)
            d[0] = max(d[0], x - y - i)
            d[1] = min(d[1], x - y - i)

        return max(a[0] - a[1], b[0] - b[1], c[0] - c[1], d[0] - d[1])
            
# @lc code=end

