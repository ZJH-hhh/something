#
# @lc app=leetcode.cn id=1170 lang=python3
#
# [1170] 比较字符串最小字母出现频次
#

# @lc code=start
from bisect import bisect, bisect_left, bisect_right


class Solution:
    def numSmallerByFrequency(self, queries: List[str], words: List[str]) -> List[int]:
        fw = []
        for word in words:
            minv = min(word)
            cnt = 0
            for c in word:
                cnt += c == minv
            fw.append(cnt)
        
        fw.sort()
        res = []
        n = len(words)
        for i, word in enumerate(queries):
            minv = min(word)
            cnt = 0
            for c in word:
                cnt += c == minv
            j = bisect_right(fw, cnt)
            res.append(n - j)

        return res                

# @lc code=end

