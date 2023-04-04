#
# @lc app=leetcode.cn id=33 lang=python3
#
# [33] 搜索旋转排序数组
#

# @lc code=start
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        if not nums: return -1

        l, r = 0, len(nums) - 1
        while l < r:
            mid = l + r >> 1
            if nums[mid] == target: return mid

            if nums[l] <= nums[mid]:
                if nums[l] <= target and target < nums[mid]:
                    r = mid
                else: l = mid + 1
            else:
                if target >= nums[mid] and target <= nums[r]:
                    l = mid + 1
                else: r = mid

        return l 
# @lc code=end

