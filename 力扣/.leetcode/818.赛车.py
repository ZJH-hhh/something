#
# @lc app=leetcode.cn id=818 lang=python3
#
# [818] 赛车
#

# @lc code=start
from cmath import inf


class Solution:
    def racecar(self, target: int) -> int:
        f = [inf] * (10 ** 4 + 5)
        for i in range(1, target + 1):
            forward = 1
            while (1 << forward) - 1 < 2 * i:
                forward_distance = (1 << forward) - 1
                if forward_distance == i: f[i] = forward
                elif forward_distance > i: 
                    f[i] = min(f[i], f[forward_distance - i] + forward + 1)
                else:
                    backward = 0
                    while backward < forward:
                        backward_distance  = (1 << backward) - 1
                        f[i] = min(f[i], f[i - forward_distance + backward_distance] + forward + backward + 2)
                        backward += 1
                forward += 1

        return f[target]
# @lc code=end

