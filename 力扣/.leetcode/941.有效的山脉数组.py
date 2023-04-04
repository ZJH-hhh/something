#
# @lc app=leetcode.cn id=941 lang=python3
#
# [941] 有效的山脉数组
#

# @lc code=start
class Solution:
    def validMountainArray(self, arr: List[int]) -> bool:
        i, n = 1, len(arr)
        if n < 3: return False

        while i < n and arr[i] > arr[i - 1]: i += 1
        if i == n or i == 1: return False

        while i < n and arr[i] < arr[i - 1]: i += 1
        return i == n
# @lc code=end

