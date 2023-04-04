#
# @lc app=leetcode.cn id=856 lang=python3
#
# [856] 括号的分数
#

# @lc code=start
class Solution:
    def scoreOfParentheses(self, s: str) -> int:
        stk = [0]
        for c in s:
            if c == '(': stk.append(0)
            else: 
                v = stk.pop()
                stk[-1] += max(2 * v, 1)
            print(stk)
        return stk[-1]

# @lc code=end

