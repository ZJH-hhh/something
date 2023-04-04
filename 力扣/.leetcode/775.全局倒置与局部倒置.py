#
# @lc app=leetcode.cn id=775 lang=python3
#
# [775] 全局倒置与局部倒置
#

# @lc code=start
class Solution:
    def isIdealPermutation(self, nums: List[int]) -> bool:
        n = len(nums)
        partial = 0
        for i in range(1, n):
            partial += nums[i] < nums[i - 1]

        def merge_sort(l: int, r: int) -> int:
            if l >= r: return 0
            mid = l + r >> 1
            res = merge_sort(l, mid) + merge_sort(mid + 1, r)
            
            k, i, j = 0, l, mid + 1
            while i <= mid and j <= r:
                if nums[i] <= nums[j]:
                    tmp[k] = nums[i]
                    k, i = k + 1, i + 1
                else:
                    tmp[k] = nums[j]
                    k, j = k + 1, j + 1
                    res += mid - i + 1

            while i <= mid: 
                tmp[k] = nums[i]
                k, i = k + 1, i + 1
            while j <= r:
                tmp[k] = nums[j]
                k, j = k + 1, j + 1

            i, j = l, 0
            while i <= r:
                nums[i] = tmp[j]
                i, j = i + 1, j + 1

            return res

        tmp = [0] * n
        all = merge_sort(0, n - 1)
        return all == partial

# @lc code=end

