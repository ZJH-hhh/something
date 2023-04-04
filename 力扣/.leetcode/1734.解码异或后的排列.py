#
# @lc app=leetcode.cn id=1734 lang=python3
#
# [1734] 解码异或后的排列
#

# @lc code=start

"""
e[0] = a[0] ^ a[1]
e[1] = a[1] ^ a[2]
e[2] = a[2] ^ a[3]
e[3] = a[3] ^ a[4]
e[4] = a[4] ^ a[5]
e[5] = a[5] ^ a[6]
"""

class Solution:
    def decode(self, encoded: List[int]) -> List[int]:
        n = len(encoded) + 1
        total = 1
        for i in range(2, n + 1):
            total ^= i

        t = 0
        for i in range(1, n, 2):
            t ^= encoded[i]
        
        res = [0] * n
        res[0] = total ^ t

        for i in range(1, n):
            res[i] = res[i - 1] ^ encoded[i - 1]
        
        return res

# @lc code=end

