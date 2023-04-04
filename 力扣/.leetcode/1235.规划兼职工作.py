#
# @lc app=leetcode.cn id=1235 lang=python3
#
# [1235] 规划兼职工作
#

# @lc code=start
from bisect import bisect, bisect_left, bisect_right
from cmath import inf


class Solution:
    def jobScheduling(self, st: List[int], ed: List[int], profit: List[int]) -> int:
        jobs = sorted(zip(ed, st, profit))
        n = len(st)
        
        f = [0] * (n + 1)
        for i, (a, b, w) in enumerate(jobs, 1):
            j = bisect_right(jobs, (b, inf, inf), hi = i)
            f[i] = max(f[i - 1], f[j] + w)

        return f[n]

# @lc code=end

