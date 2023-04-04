#
# @lc app=leetcode.cn id=904 lang=python3
#
# [904] 水果成篮
#

# @lc code=start
from collections import defaultdict
from distutils.command.build_scripts import first_line_re


class Solution:
    def totalFruit(self, fruits: List[int]) -> int:
        l = res = 0
        s = defaultdict(int)
        for r, fruit in enumerate(fruits):
            s[fruit] += 1
            while len(s) > 2:
                s[fruits[l]] -= 1
                if s[fruits[l]] == 0:
                    s.pop(fruits[l])
                l += 1
            res = max(res, r - l + 1)
        
        return res


# @lc code=end

