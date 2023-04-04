#
# @lc app=leetcode.cn id=940 lang=python3
#
# [940] 不同的子序列 II
#

# @lc code=start
MOD = 10 ** 9 + 7

class Solution:
    def distinctSubseqII(self, s: str) -> int:
        f = [0] * 26
        for c in s:
            t = ord(c) - ord('a')
            f[t] = (1 + sum(f)) % MOD
        return sum(f) % MOD

# @lc code=end

