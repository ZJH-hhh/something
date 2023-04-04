#
# @lc app=leetcode.cn id=1822 lang=python3
#
# [1822] 数组元素积的符号
#

# @lc code=start
class Solution:
    def arraySign(self, nums: List[int]) -> int:
        cnt = 0
        for num in nums:
            if num == 0: return 0
            cnt += num < 0
        return -1 if cnt & 1 else 1
# @lc code=end

