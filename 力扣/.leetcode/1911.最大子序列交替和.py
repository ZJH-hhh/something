#
# @lc app=leetcode.cn id=1911 lang=python3
#
# [1911] 最大子序列交替和
#


# @lc code=start
class Solution:
    def maxAlternatingSum(self, nums: List[int]) -> int:
        res = pre = 0
        for num in nums:
            if num > pre: 
                res += num - pre
                print(num, pre)
            pre = num
        return res
# @lc code=end

