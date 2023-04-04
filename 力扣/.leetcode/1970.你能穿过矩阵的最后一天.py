#
# @lc app=leetcode.cn id=1970 lang=python3
#
# [1970] 你能穿过矩阵的最后一天
#

# @lc code=start

from collections import deque

class Solution:
    def latestDayToCross(self, n: int, m: int, cells: List[List[int]]) -> int:
        l, r = 0, n * m
        dir = [(-1, 0), (0, -1), (1, 0), (0, 1)]

        while l < r:
            mid = l + r + 1 >> 1

            grid = [[1] * m for _ in range(n)]
            for i in range(mid):
                x, y = cells[i][0] - 1, cells[i][1] - 1
                grid[x][y] = 0

            q = deque()
            for i in range(m):
                if grid[0][i]:
                    q.append((0, i))
                    grid[0][i] = 0

            flag = False
            while q:
                x, y = q.popleft()
                for dx, dy in dir:
                    a, b = x + dx, y + dy
                    if a < 0 or a >= n or b < 0 or b >= m: continue
                    if not grid[a][b]: continue
                    if a == n - 1:
                        print(a, b)
                        flag = True
                        break

                    q.append((a, b))
                    grid[a][b] = 0

            if flag: l = mid
            else: r = mid - 1

        return l

# @lc code=end

