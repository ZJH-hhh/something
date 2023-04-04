#
# @lc app=leetcode.cn id=870 lang=python3
#
# [870] 优势洗牌
#

# @lc code=start
class Solution:
    def advantageCount(self, nums1: List[int], nums2: List[int]) -> List[int]:
        nums1.sort()
        n, minidx = len(nums1), 0
        res = []
        st = [False] * n
        for i in range(n):
            l, r = 0, n
            while l < r:
                mid = l + r >> 1
                if nums1[mid] > nums2[i]: r = mid
                else: l = mid + 1
            
            while l < n and st[l] : l += 1
            if l == n: 
                while st[minidx]: minidx += 1
                res.append(nums1[minidx])
                st[minidx] = True
            else: 
                res.append(nums1[l])
                st[l] = True

        return res

# @lc code=end

