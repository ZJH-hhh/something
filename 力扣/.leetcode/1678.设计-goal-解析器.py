#
# @lc app=leetcode.cn id=1678 lang=python3
#
# [1678] 设计 Goal 解析器
#

# @lc code=start
class Solution:
    def interpret(self, s: str) -> str:
        res = ''
        i = 0
        while i < len(s):
            if s[i] == 'G': res += 'G'
            elif s[i] == '(':
                if s[i + 1] == ')': 
                    res += 'o'
                    i += 1
                else:
                    res += 'al'
                    i += 3
            i += 1
        return res
# @lc code=end

