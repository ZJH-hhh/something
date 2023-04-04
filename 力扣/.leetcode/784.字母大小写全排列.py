#
# @lc app=leetcode.cn id=784 lang=python3
#
# [784] 字母大小写全排列
#

# @lc code=start
from curses.ascii import islower


class Solution:
    def letterCasePermutation(self, s: str) -> List[str]:
        res = []
        n = len(s)
        t = list(s)

        def dfs(u: int):
            if u == n:
                res.append("".join(t))
                return

            dfs(u + 1)
            if t[u].isalpha():
                t[u] = chr(ord(t[u]) ^ 32)
                dfs(u + 1)

        dfs(0)

        return res
# @lc code=end

