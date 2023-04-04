#
# @lc app=leetcode.cn id=792 lang=python3
#
# [792] 匹配子序列的单词数
#

# @lc code=start
from collections import defaultdict
from bisect import bisect_left

class Solution:
    def numMatchingSubseq(self, s: str, words: List[str]) -> int:
        pos = defaultdict(list)
        for i, c in enumerate(s):
            pos[c].append(i)
        res = 0
        for word in words:
            flag, idx = True, 0
            for c in word:
                i = bisect_left(pos[c], idx, lo=0, hi=len(pos[c]))
                if i >= len(pos[c]):
                    flag = False
                    break
                idx = pos[c][i] + 1
            if flag: res += 1
        return res
# @lc code=end

