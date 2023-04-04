#
# @lc app=leetcode.cn id=788 lang=python3
#
# [788] 旋转数字
#

# @lc code=start
class Solution:
    def rotatedDigits(self, n: int) -> int:
        a = [0]
        while n:
            a.append(n % 10)
            n //= 10

        f = [[-1] * 15 for _ in range(15)]
        
        def dfs(pos: int, st: int, limit: bool) -> int:
            if not pos: return st
            if not limit and f[pos][st] != -1:
                return f[pos][st]

            res = 0
            up = a[pos] if limit else 9
            for i in range(0, up + 1):
                if i == 3 or i == 4 or i == 7:
                    continue
                res += dfs(pos - 1, st or i == 2 or i == 5 or i == 6 or i == 9, limit and i == up)
            
            if not limit:
                f[pos][st] = res
            
            return res if limit else f[pos][st]
        
        return dfs(len(a) - 1, 0, True)
                
            
# @lc code=end

