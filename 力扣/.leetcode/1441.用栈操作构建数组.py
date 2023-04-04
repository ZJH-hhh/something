#
# @lc app=leetcode.cn id=1441 lang=python3
#
# [1441] 用栈操作构建数组
#

# @lc code=start
class Solution:
    def buildArray(self, target: List[int], n: int) -> List[str]:
        res = []
        target = [0] + target
        for i in range(1, len(target)):
            x = target[i] - target[i - 1]
            for _ in range(x - 1):
                res.append("Push")
                res.append("Pop")
            res.append("Push")
        return res
# @lc code=end

