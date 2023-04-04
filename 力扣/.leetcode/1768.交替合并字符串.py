#
# @lc app=leetcode.cn id=1768 lang=python3
#
# [1768] 交替合并字符串
#

# @lc code=start
class Solution:
    def mergeAlternately(self, word1: str, word2: str) -> str:
        n, m = len(word1), len(word2)
        i = 0
        res = ""
        while i < max(n, m):
            if i < n: res += word1[i]
            if i < m: res += word2[i]
            i += 1

        return res
# @lc code=end

