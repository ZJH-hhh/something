#
# @lc app=leetcode.cn id=934 lang=python3
#
# [934] 最短的桥
#

# @lc code=start

"""
0 0 1 0 1
0 1 1 0 1
0 1 0 0 1
0 0 0 0 0
0 0 0 0 0
"""

from collections import deque

class Solution:
    def shortestBridge(self, grid: List[List[int]]) -> int:
        n = len(grid)
        dir = [(-1, 0), (0, -1), (1, 0), (0, 1)]
        q = deque()

        def dfs(x: int, y: int):
            q.append((x, y))
            grid[x][y] = -1
            for dx, dy in dir:
                a, b = x + dx, y + dy
                if a < 0 or a >= n or b < 0 or b >= n: continue
                if grid[a][b] != 1: continue
                dfs(a, b)

        for i in range(n):
            flag = False
            for j in range(n):
                if grid[i][j] == 1:
                    flag = True
                    dfs(i, j)
                    break
            if flag: break

        res = 0
        while 1:
            size = len(q)
            for _ in range(size):
                x, y = q.popleft()
                for dx, dy in dir:
                    a, b = x + dx, y + dy
                    if a < 0 or a >= n or b < 0 or b >= n: continue
                    if grid[a][b] == -1: continue
                    if grid[a][b] == 1: return res
                    q.append((a, b))
                    grid[a][b] = -1
            res += 1
            
        return res

# @lc code=end