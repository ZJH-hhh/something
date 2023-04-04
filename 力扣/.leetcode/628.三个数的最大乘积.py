#
# @lc app=leetcode.cn id=628 lang=python3
#
# [628] 三个数的最大乘积
#

# @lc code=start

from cmath import inf


class Solution:
    def maximumProduct(self, nums: List[int]) -> int:
        minv1, minv2 = 1001, 1001
        maxv1, maxv2, maxv3 = -1001, -1001, -1001

        for num in nums:
            if num < minv1:
                minv2 = minv1
                minv1 = num
            elif num < minv2:
                minv2 = num

            if num > maxv1:
                maxv3 = maxv2
                maxv2 = maxv1
                maxv1 = num
            elif num > maxv2:
                maxv3 = maxv2
                maxv2 = num
            elif num > maxv3:
                maxv3 = num

        return max(maxv1 * maxv2 * maxv3, maxv1 * minv1 * minv2)


# @lc code=end

