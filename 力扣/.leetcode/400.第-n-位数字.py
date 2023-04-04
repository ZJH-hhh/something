#
# @lc app=leetcode.cn id=400 lang=python3
#
# [400] 第 N 位数字
#

# @lc code=start
class Solution:
    def findNthDigit(self, n: int) -> int:
        len, cnt = 1, 9
        while n > len * cnt:
            n -= len * cnt
            len += 1
            cnt *= 10

        l = 10 ** (len - 1)
        l += n // len - 1
        n -= len * (n // len)
        return l % 10 if n == 0 else (l + 1) // (10 ** (len - n)) % 10

# @lc code=end

