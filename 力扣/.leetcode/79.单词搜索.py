#
# @lc app=leetcode.cn id=79 lang=python3
#
# [79] 单词搜索
#

# @lc code=start
"""
A B C E
S F C S
A D E E
"""

class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        n, m = len(board), len(board[0])
        if len(word) > n * m: return False

        dir = [(-1, 0), (0, -1), (1, 0), (0, 1)]
        st = [[False] * m for _ in range(n)]

        def dfs(x: int, y: int, u: int) -> bool:
            if u == len(word) - 1: return True

            for dx, dy in dir:
                a, b = x + dx, y + dy
                if a < 0 or a >= n or b < 0 or b >= m: continue
                if st[a][b]: continue
                if board[a][b] != word[u + 1]: continue
                st[a][b] = True
                if dfs(a, b, u + 1): return True
                st[a][b] = False

            return False

        for i in range(n):
            for j in range(m):
                if board[i][j] == word[0]:
                    st[i][j] = True
                    if dfs(i, j, 0): return True
                    st[i][j] = False
        return False
# @lc code=end

