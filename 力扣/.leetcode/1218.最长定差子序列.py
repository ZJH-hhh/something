#
# @lc app=leetcode.cn id=1218 lang=python3
#
# [1218] 最长定差子序列
#

# @lc code=start
from array import array


class Solution:
    def longestSubsequence(self, arr: List[int], d: int) -> int:
        n = len(arr)
        mp = defaultdict(int)
        res = 0
        for x in arr:
            mp[x] = mp[x - d] + 1
            res = max(res, mp[x])

        return res

# @lc code=end

