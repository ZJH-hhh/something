#
# @lc app=leetcode.cn id=263 lang=python3
#
# [263] 丑数
#

# @lc code=start
class Solution:
    def isUgly(self, n: int) -> bool:
        if n <= 0: return False
        
        for x in (2, 3, 5): 
            while n % x == 0: n //= x
        
        return n == 1
# @lc code=end

