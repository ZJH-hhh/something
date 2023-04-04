#
# @lc app=leetcode.cn id=392 lang=python3
#
# [392] 判断子序列
#

# @lc code=start
class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        if len(s) > len(t):
            return False

        i = j = 0
        for i, c in enumerate(s):
            while j < len(t) and t[j] != c: j += 1
            if j == len(t):
                return False
            j += 1
        return True
# @lc code=end

