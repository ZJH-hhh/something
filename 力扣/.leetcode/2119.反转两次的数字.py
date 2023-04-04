#
# @lc app=leetcode.cn id=2119 lang=python3
#
# [2119] 反转两次的数字
#

# @lc code=start
class Solution:
    def isSameAfterReversals(self, num: int) -> bool:
        num = str(num)
        return num[-1] != '0' if len(num) > 1 else True
# @lc code=end

