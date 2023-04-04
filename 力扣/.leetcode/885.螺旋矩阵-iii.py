#
# @lc app=leetcode.cn id=885 lang=python3
#
# [885] 螺旋矩阵 III
#

"""
"""

# @lc code=start
class Solution:
    def spiralMatrixIII(self, n: int, m: int, x: int, y: int) -> List[List[int]]:
        dir = [(0, 1), (1, 0), (0, -1), (-1, 0)]
        res = [[0, 0] for _ in range(n * m)]
        res[0] = [x, y]
        dist = 1
        d = 0
        cnt = 1
        while cnt < n * m:
            dx, dy = dir[d][0], dir[d][1]
            for step in range(dist):
                x += dx
                y += dy
                if x < 0 or x >= n or y < 0 or y >= m: continue
                res[cnt] = [x, y]
                cnt += 1
                if cnt == n * m: break
            
            dist += d % 2
            d = (d + 1) % 4

        return res

# @lc code=end

