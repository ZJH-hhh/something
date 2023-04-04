#
# @lc app=leetcode.cn id=583 lang=python3
#
# [583] 两个字符串的删除操作
#

# @lc code=start
class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        f = [[0] * 505 for _ in range(505)]
        n, m = len(word1), len(word2)
        word1 = 'a' + word1
        word2 = 'b' + word2
        for i in range(1, len(word1)):
            for j in range(1, len(word2)):
                if word1[i] == word2[j]:
                    f[i][j] = f[i - 1][j - 1] + 1
                else: f[i][j] = max(f[i - 1][j], f[i][j - 1])
        
        return n - f[n][m] + m - f[n][m]
# @lc code=end

