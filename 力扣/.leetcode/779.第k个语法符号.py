#
# @lc app=leetcode.cn id=779 lang=python3
#
# [779] 第K个语法符号
#

# @lc code=start
class Solution:
    def kthGrammar(self, n: int, k: int) -> int:
        return (k - 1).bit_count() & 1
# @lc code=end

