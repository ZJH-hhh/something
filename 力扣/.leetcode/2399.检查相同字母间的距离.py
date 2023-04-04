#
# @lc app=leetcode.cn id=2399 lang=python3
#
# [2399] 检查相同字母间的距离
#

# @lc code=start
from dis import dis


class Solution:
    def checkDistances(self, s: str, distance: List[int]) -> bool:
        n = len(s)
        pre = [-1] * 26
        for i, c in enumerate(s):
            j = ord(c) - ord('a')
            if pre[j] == -1:
                pre[j] = i
            elif i - pre[j] - 1 != distance[j]:
                return False
        
        return True
# @lc code=end 

