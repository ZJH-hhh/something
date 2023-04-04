#
# @lc app=leetcode.cn id=2215 lang=python3
#
# [2215] 找出两数组的不同
#

# @lc code=start
class Solution:
    def findDifference(self, nums1: List[int], nums2: List[int]) -> List[List[int]]:
        set1, set2 = set(nums1), set(nums2)
        return [list(set1 -set2), list(set2 - set1)]
        
# @lc code=end

