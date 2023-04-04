#
# @lc app=leetcode.cn id=1462 lang=python3
#
# [1462] 课程表 IV
#

# @lc code=start
class Solution:
    def checkIfPrerequisite(self, numCourses: int, prerequisites: List[List[int]], queries: List[List[int]]) -> List[bool]:
        g = [[] for _ in range(numCourses)]
        st = [False] * numCourses
        for a, b in prerequisites:
            g[a].append(b)

        def dfs(a: int, b: int) -> bool:
            for x in g[a]:
                if x == b: return True
                if dfs(x, b): return True
            return False

        res = []
        for a, b in queries:
            if dfs(a, b): 
                res.append(True)
            else:
                res.append(False)

        return res
# @lc code=end

