#
# @lc app=leetcode.cn id=1958 lang=python3
#
# [1958] 检查操作是否合法
#

# @lc code=start
class Solution:
    def checkMove(self, board: List[List[str]], rMove: int, cMove: int, color: str) -> bool:
        n, m = len(board), len(board[0])
        board[rMove][cMove] = color

        def check(x: int, y: int) -> bool:
            return x >= 0 and x < n and y >= 0 and y < m

        for dx in range(-1, 2):
            for dy in range(-1, 2):
                if dx == dy == 0: continue
                x, y, length = rMove + dx, cMove + dy, 2
                while check(x, y) and board[x][y] != color:
                    if board[x][y] == '.': break
                    x += dx
                    y += dy
                    length += 1
                if length >= 3 and check(x, y) and board[x][y] == color: return True

        return False

# @lc code=end

