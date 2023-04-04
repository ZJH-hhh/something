#
# @lc app=leetcode.cn id=902 lang=python3
#
# [902] 最大为 N 的数字组合
#

# @lc code=start
from functools import cache


class Solution:
    def atMostNGivenDigitSet(self, digits: List[str], n: int) -> int:
        digits = list(map(int, digits))
        
        nums = [-1]
        while n:
            nums.append(n % 10)
            n //= 10

        f = [-1] * 15

        def dfs(pos: int, pre: bool, limit: bool) -> int:
            if pos == 0: return int(pre)
            if not limit and pre and f[pos] != -1: return f[pos]

            res = 0
            if not pre:
                res = dfs(pos - 1, False, False)
            up = nums[pos] if limit else 9
            for d in digits:
                if d > up: break
                res += dfs(pos - 1, True, limit and d == up)

            if not limit and pre: f[pos] = res
            return res
        
        return dfs(len(nums) - 1, False, True)
# @lc code=end

