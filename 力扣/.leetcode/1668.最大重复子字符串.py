#
# @lc app=leetcode.cn id=1668 lang=python3
#
# [1668] 最大重复子字符串
#

# @lc code=start
class Solution:
    def maxRepeating(self, sequence: str, word: str) -> int:
        if word not in sequence: return 0
        
        k = 1
        while word * k in sequence:
            k += 1
        
        return k - 1
# @lc code=end

