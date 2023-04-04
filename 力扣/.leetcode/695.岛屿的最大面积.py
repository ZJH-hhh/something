#
# @lc app=leetcode.cn id=695 lang=python3
#
# [695] 岛屿的最大面积
#

# @lc code=start
class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        st = [[False] * (55) for _ in range(55)]
        dir = [(-1, 0), (0, -1), (1, 0), (0, 1)]
        n, m = len(grid), len(grid[0])

        def dfs(x, y) -> int:
            res = 1
            st[x][y] = True

            for i in range(4):
                a, b = x + dir[i][0], y + dir[i][1]
                if a < 0 or a >= n or b < 0 or b >= m: continue
                if st[a][b] or grid[a][b] == 0: continue
                res += dfs(a, b)

            return res

        res = 0
        for i in range(n):
            for j in range(m):
                if grid[i][j] == 1:
                    res = max(res, dfs(i, j))
        
        return res
# @lc code=end

