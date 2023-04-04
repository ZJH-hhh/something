#
# @lc app=leetcode.cn id=801 lang=python3
#
# [801] 使序列递增的最小交换次数
#

# @lc code=start
class Solution:
    def minSwap(self, a: List[int], b: List[int]) -> int:
        n = len(a)
        INF = 1e6
        f = [[0, 1], [INF, INF]]
        for i in range(1, n):
            f[i & 1][0], f[i & 1][1] = INF, INF
            if a[i] > a[i - 1] and b[i] > b[i - 1]:
                f[i & 1][0] = f[i - 1 & 1][0]
                f[i & 1][1] = f[i - 1 & 1][1] + 1
            if a[i] > b[i - 1] and b[i] > a[i - 1]:
                f[i & 1][0] = min(f[i & 1][0], f[i - 1 & 1][1])
                f[i & 1][1] = min(f[i & 1][1], f[i - 1 & 1][0] + 1)

        return min(f[n - 1 & 1][0], f[n - 1 & 1][1])

# @lc code=end

