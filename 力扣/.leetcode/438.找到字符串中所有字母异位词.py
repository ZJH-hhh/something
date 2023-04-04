#
# @lc app=leetcode.cn id=438 lang=python3
#
# [438] 找到字符串中所有字母异位词
#

# @lc code=start
from collections import defaultdict
from typing import Counter


class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        mpp = Counter()
        for c in p: mpp[c] += 1

        res = []
        l = r = 0
        n = len(s)
        mps = Counter()
        while r < n:
            mps[s[r]] += 1
            if r > len(p) - 1: 
                mps[s[l]] -= 1
                l += 1
            
            flag = True
            for i in range(ord('a'), ord('z') + 1):
                c = chr(i)
                if mps[c] != mpp[c]:
                    flag = False
                    break
            
            if flag: res.append(l)
            r += 1
        
        return res

# @lc code=end

