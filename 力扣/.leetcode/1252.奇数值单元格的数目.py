#
# @lc app=leetcode.cn id=1252 lang=python3
#
# [1252] 奇数值单元格的数目
#

# @lc code=start
class Solution:
    def oddCells(self, n: int, m: int, indices: List[List[int]]) -> int:
        a = [[0] * m for _ in range(n)]
        for x, y in indices:
            for i in range(m): a[x][i] += 1
            for i in range(n): a[i][y] += 1
        
        res = 0
        for r in a:
            for c in r:
                res += c & 1
        return res
# @lc code=end

