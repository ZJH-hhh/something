#
# @lc app=leetcode.cn id=862 lang=python3
#
# [862] 和至少为 K 的最短子数组
#

# @lc code=start

from cmath import inf
from collections import deque

class Solution:
    def shortestSubarray(self, nums: List[int], k: int) -> int:
        n = len(nums)
        nums = [0] + nums
        s = [0] * (n + 1)
        for i in range(1, n + 1): s[i] = s[i - 1] + nums[i]

        q = deque()
        res = inf

        for i in range(0, n + 1):
            while q and s[i] - s[q[0]] >= k:
                res = min(res, i - q.popleft())
            while q and s[i] <= s[q[-1]]:
                q.pop()
            q.append(i)

        return res if res != inf else -1

# @lc code=end

