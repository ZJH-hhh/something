#
# @lc app=leetcode.cn id=1071 lang=python3
#
# [1071] 字符串的最大公因子
#

# @lc code=start
class Solution:
    def gcdOfStrings(self, str1: str, str2: str) -> str:
        res, tmp = "", ""
        str = min(str1, str2)
        for i, c in enumerate(str, 1):
            tmp += c
            if len(str1) % i or len(str2) % i: continue
            n1, n2 = len(str1) // i, len(str2) // i
            if tmp * n1 == str1 and tmp * n2 == str2: 
                res = tmp

        return res
# @lc code=end

