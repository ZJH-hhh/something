#
# @lc app=leetcode.cn id=816 lang=python3
#
# [816] 模糊坐标
#

# @lc code=start
class Solution:
    def ambiguousCoordinates(self, s: str) -> List[str]:
        s = s[1:-1]
        n = len(s)

        def find(l: int, r: int) -> list[str]:
            res = []
            if l == r or s[l] != '0': res.append(s[l: r + 1])
            for i in range(l, r):
                a, b = s[l: i + 1], s[i + 1: r + 1]
                if len(a) > 1 and a[0] == '0': continue
                if b[-1] == '0': continue
                res.append(a + '.' + b)
            return res

        res = []
        for i in range(0, n - 1):
            a, b = find(0, i), find(i + 1, n - 1)
            for x in a:
                for y in b:
                    res.append('(' + x + ', ' + y + ')')

        return res
# @lc code=end

