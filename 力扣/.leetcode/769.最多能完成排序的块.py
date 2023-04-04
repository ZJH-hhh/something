#
# @lc app=leetcode.cn id=769 lang=python3
#
# [769] 最多能完成排序的块
#

# @lc code=start
class Solution:
    def maxChunksToSorted(self, arr: List[int]) -> int:
        n = len(arr)
        s = [0] * n
        for i in range(1, n):
            s[i] = s[i - 1] + i
        
        res = sum = 0
        for i in range(n):
            sum += arr[i]
            if sum == s[i]:
                res += 1
        return res
# @lc code=end

