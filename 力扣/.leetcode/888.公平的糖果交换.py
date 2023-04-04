#
# @lc app=leetcode.cn id=888 lang=python3
#
# [888] 公平的糖果交换
#

# @lc code=start
class Solution:
    def fairCandySwap(self, aliceSizes: List[int], bobSizes: List[int]) -> List[int]:
        n, m = sum(aliceSizes), sum(bobSizes)
        cnt = (n + m) // 2
        
        for x in aliceSizes:
            if cnt - (n - x) in bobSizes:
                return [x, cnt - (n - x)]
        
        return [-1, -1]

# @lc code=end

