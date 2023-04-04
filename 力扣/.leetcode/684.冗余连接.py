#
# @lc app=leetcode.cn id=684 lang=python3
#
# [684] 冗余连接
#

# @lc code=start
class Solution:
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        n = len(edges)
        fa = [i for i in range(n + 1)]

        def find(x: int) -> int:
            if x != fa[x]: fa[x] = find(fa[x])
            return fa[x]

        for a, b in edges:
            if find(a) != find(b):
                fa[find(a)] = find(b)
            else:
                return [a, b]

        return [0, 0]
        
# @lc code=end

