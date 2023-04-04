#
# @lc app=leetcode.cn id=754 lang=python3
#
# [754] 到达终点数字
#

# @lc code=start
class Solution:
    def reachNumber(self, target: int) -> int:
        target = abs(target)
        n = ceil((-1 + (8 * target + 1) ** 0.5) / 2)
        return n if (n * (n + 1) // 2 - target) % 2 == 0 else n + 1 + n % 2
# @lc code=end

