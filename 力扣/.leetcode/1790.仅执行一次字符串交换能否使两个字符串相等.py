#
# @lc app=leetcode.cn id=1790 lang=python3
#
# [1790] 仅执行一次字符串交换能否使两个字符串相等
#

# @lc code=start
class Solution:
    def areAlmostEqual(self, s1: str, s2: str) -> bool:
        pos1, pos2, cnt = -1, -1, 0
        for i in range(len(s1)):
            if s1[i] != s2[i]:
                cnt += 1
                if cnt > 2: return False
                if pos1 == -1: pos1 = i
                else: pos2 = i
        
        return s1[pos1] == s2[pos2] and s1[pos2] == s2[pos1]

# @lc code=end

