#
# @lc app=leetcode.cn id=481 lang=python3
#
# [481] 神奇字符串
#

# @lc code=start

"""
1 2 2  
    i
"""

class Solution:
    def magicalString(self, n: int) -> int:
        s = [1, 2, 2]
        i = 2
        while len(s) < n:
            s += s[i] * [s[-1] ^ 3]
            i += 1
        
        return s[:n].count(1)
# @lc code=end

