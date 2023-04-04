#
# @lc app=leetcode.cn id=830 lang=python3
#
# [830] 较大分组的位置
#

# @lc code=start
class Solution:
    def largeGroupPositions(self, s: str) -> List[List[int]]:
        res = []
        n = len(s)
        l = r = 0
        while r < n:
            while r < n and s[r] == s[l]: r += 1
            if r - l >= 3:
                res.append([l, r - 1])
            l = r
            r += 1
        res.sort()
        return res
# @lc code=end

