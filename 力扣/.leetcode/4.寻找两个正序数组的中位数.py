#
# @lc app=leetcode.cn id=4 lang=python3
#
# [4] 寻找两个正序数组的中位数
#

# @lc code=start

class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        n, m = len(nums1), len(nums2)
        l, r = (n + m + 1) // 2, (n + m + 2) // 2

        def getKth(l1, l2, k):
            len1, len2 = n - l1, m - l2
            if len1 == 0: return nums2[l2 + k - 1]
            if len2 == 0: return nums1[l1 + k - 1]
            if k == 1: return min(nums1[l1], nums2[l2])

            i = l1 + min(len1, k // 2) - 1
            j = l2 + min(len2, k // 2) - 1
            if nums1[i] > nums2[j]:
                return getKth(l1, j + 1, k - (j - l2 + 1))
            return getKth(i + 1, l2, k - (i - l1 + 1))

        return (getKth(0, 0, l) + getKth(0, 0, r)) / 2

# @lc code=end

