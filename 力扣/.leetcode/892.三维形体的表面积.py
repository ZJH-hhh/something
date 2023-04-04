#
# @lc app=leetcode.cn id=892 lang=python3
#
# [892] 三维形体的表面积
#

# @lc code=start
class Solution:
    def surfaceArea(self, grid: List[List[int]]) -> int:
        res, n = 0, len(grid)
        dir = [(-1, 0), (0, -1), (1, 0), (0, 1)]
        for i in range(n):
            for j in range(n):
                res += grid[i][j] * 6 - 2 *(max(0, grid[i][j] - 1))
                print(res)
                for dx, dy in dir:
                    x, y = i + dx, j + dy
                    if x < 0 or x >= n or y < 0 or y >= n: continue
                    if grid[x][y] == 0: continue
                    res -= min(grid[i][j], grid[x][y])

        return res
# @lc code=end

