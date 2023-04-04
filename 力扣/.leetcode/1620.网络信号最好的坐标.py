#
# @lc app=leetcode.cn id=1620 lang=python3
#
# [1620] 网络信号最好的坐标
#

# @lc code=start
class Solution:
    def bestCoordinate(self, towers: List[List[int]], radius: int) -> List[int]:
        d = [[0] * 55 for _ in range(55)]
        maxx = max(t[0] for t in towers)
        maxy = max(t[1] for t in towers)
        cx = cy = maxq = 0
        for x in range(maxx + 1):
            for y in range(maxy + 1):
                sum = 0
                for tx, ty, q in towers:
                    d = (tx - x) ** 2 + (ty - y) ** 2
                    if d <= radius ** 2:
                        sum += int(q / (1 + d ** 0.5))
                    if sum > maxq:
                        cx, cy, maxq = x, y, sum
        
        return [cx, cy]
# @lc code=end

