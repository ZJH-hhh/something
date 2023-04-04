#
# @lc app=leetcode.cn id=1106 lang=python3
#
# [1106] 解析布尔表达式
#

# @lc code=start
class Solution:
    def parseBoolExpr(self, expression: str) -> bool:
        stk = []
        for c in expression:
            if c == ',': continue
            if c != ')': stk.append(c)
            else:
                tmp = []
                while stk[-1] != '(':
                    tmp.append(1 if stk[-1] == 't' else 0)
                    stk.pop()
                stk.pop()
                op = stk.pop()
                if op == '!':
                    stk.append('t' if tmp == 1 else 'f')
                elif op == '&':
                    t = 1
                    for x in tmp:
                        t &= x
                    stk.append(t)
                elif op == '|':
                    t = 0
                    for x in tmp:
                        t |= x
                    stk.append(t)
        
        return bool(stk[-1])
                    
# @lc code=end

