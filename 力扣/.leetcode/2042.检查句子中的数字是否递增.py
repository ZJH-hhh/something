#
# @lc app=leetcode.cn id=2042 lang=python3
#
# [2042] 检查句子中的数字是否递增
#

# @lc code=start
class Solution:
    def areNumbersAscending(self, s: str) -> bool:
        pre = "0"
        i = 0
        while i < len(s):
            num = ""
            if s[i] >= '0' and s[i] <= '9':
                while i < len(s) and s[i] >= '0' and s[i] <= '9':
                    num += s[i]
                    i += 1
                if len(num) < len(pre):
                    return False
                if len(num) == len(pre) and num <= pre:
                    return False
                pre = num
            i += 1
        
        return True
# @lc code=end

