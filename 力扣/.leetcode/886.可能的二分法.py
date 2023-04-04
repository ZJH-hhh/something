#
# @lc app=leetcode.cn id=886 lang=python3
#
# [886] 可能的二分法
#

# @lc code=start
class Solution:
    def possibleBipartition(self, n: int, dislikes: List[List[int]]) -> bool:
        g = [[] for _ in range(n + 1)]
        for a, b in dislikes:
            g[a].append(b)
            g[b].append(a)

        color = [0] * (n + 1)
        def dfs(u: int, c: int) -> bool:
            color[u] = c
            for t in g[u]:
                if color[t] == 0:
                    if not dfs(t, -c):
                        return False
                elif color[t] == c:
                    return False
            
            return True

        for i in range(n + 1):
            if color[i] == 0:
                if not dfs(i, 1):
                    return False
            
        return True

# @lc code=end

