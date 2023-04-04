#
# @lc app=leetcode.cn id=864 lang=python3
#
# [864] 获取所有钥匙的最短路径
#

# @lc code=start
from collections import deque


class Solution:
    def shortestPathAllKeys(self, grid: List[str]) -> int:
        n, m = len(grid), len(grid[0])
        d = [[float('inf') * m for _ in range(n)]]
        dir = [(-1, 0), (0, -1), (1, 0), (0, 1)]
        q = deque()
        vis = set()
        x = y = k = 0
        for i in range(n):
            for j in range(m):
                if grid[i][j] == '@':
                    q.append((i, j, 0))
                    vis.add((i, j, 0))
                elif grid[i][j].islower(): k += 1

        step = 0
        while q:
            length = len(q)
            for _ in range(length):
                x, y, keys = q.popleft()
                if keys == (1 << k) - 1:
                    return step

                for dx, dy in dir:
                    a, b = x + dx, y + dy
                    state = keys
                    if a < 0 or a >= n or b < 0 or b >= m: continue
                    c = grid[a][b]
                    if c == '#': continue
                    if c.isupper() and (state >> (ord(c) - ord('A')) & 1) == 0:
                        continue 
                    if c.islower(): state |= 1 << (ord(c) - ord('a'))
                    if (a, b, state) not in vis:
                        vis.add((a, b, state))
                        q.append((a, b, state))
            step += 1   
        
        return -1
                    
# @lc code=end

