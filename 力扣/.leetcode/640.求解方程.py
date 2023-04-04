#
# @lc app=leetcode.cn id=640 lang=python3
#
# [640] 求解方程
#

# @lc code=start
class Solution:
    def solveEquation(self, equation: str) -> str:
        l, r = equation.split('=')
        lc = lv = 0
        i, pre = len(l) - 1, len(l)
        while i >= 0:
            if l[i] == 'x':
                pre = i
                i -= 1
                while i >= 0 and ord(l[i]) >= ord('0') and ord(l[i]) <= ord('9'):
                    i -= 1
                if i != -1: s = l[i:pre]
                else: s = l[:pre]
                if i == pre - 1: s += '1'
                lc += int(s)
            elif ord(l[i]) >= ord('0') and ord(l[i]) <= ord('9'):
                pre = i + 1
                while i >= 0 and ord(l[i]) >= ord('0') and ord(l[i]) <= ord('9'):
                    i -= 1
                if i != -1: s = l[i:pre]
                else: s = l[:pre]
                lv += int(s)
            i -= 1

        rc = rv = 0
        i, pre = len(r) - 1, len(r)
        while i >= 0:
            if r[i] == 'x':
                pre = i
                i -= 1
                while i >= 0 and ord(r[i]) >= ord('0') and ord(r[i]) <= ord('9'):
                    i -= 1
                if i != -1: s = r[i:pre]
                else: s = r[:pre]
                if i == pre - 1: s += '1'
                rc += int(s)
            elif ord(r[i]) >= ord('0') and ord(r[i]) <= ord('9'):
                pre = i + 1
                while i >= 0 and ord(r[i]) >= ord('0') and ord(r[i]) <= ord('9'):
                    i -= 1
                if i != -1: s = r[i:pre]
                else: s = r[:pre]
                rv += int(s)
            i -= 1
        
        coefficient = lc - rc
        val = rv - lv
        if coefficient == 0 and val != 0: return "No solution"

        if coefficient == 0 and val == 0: return "Infinite solutions"

        x = val // coefficient
        if coefficient * x != val: return "No solution"

        return "x={}".format(x)

# @lc code=end

