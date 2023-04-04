#
# @lc app=leetcode.cn id=685 lang=python3
#
# [685] 冗余连接 II
#

# @lc code=start
"""
1.附加边指向根节点，那么根节点一定处在在环路中
    需要删掉构成环的最后一条边
2.附加边不指向根节点， 那么存在唯一一个入度为2的节点
    需要删除入度为2的节点的其中一条边
"""

class Solution:
    def findRedundantDirectedConnection(self, edges: List[List[int]]) -> List[int]:
        n = len(edges)
        fa = [i for i in range(n + 1)]
        ins = [0] * (n + 1)
        in_two = [0, 0]

        def find(x: int) -> int:
            if x != fa[x]: fa[x] = find(fa[x])
            return fa[x]

        def is_tree(edges: List[List[int]]) -> bool:


        for a, b in edges:
            if ins[b] == 1:

        
        for a, b in edges:
            if find(a) != find(b):
                fa[find(a)] = find(b)
            else:
                return [a, b]
        
        return [0, 0]
# @lc code=end