#
# @lc app=leetcode.cn id=2409 lang=python3
#
# [2409] 统计共同度过的日子数
#

# @lc code=start
class Solution:
    def countDaysTogether(self, arriveAlice: str, leaveAlice: str, arriveBob: str, leaveBob: str) -> int:
        if arriveAlice > leaveBob or arriveBob > leaveAlice:
            return 0
        
        mp = {
            1: 31, 2: 28, 3: 31, 4: 30, 5: 31, 6: 30,
            7: 31, 8: 31, 9: 30, 10: 31, 11: 30, 12: 31
        }

        min_leave = min(leaveAlice, leaveBob)
        max_arrive = max(arriveAlice, arriveBob)

        a, b = map(int, max_arrive.split('-'))
        c, d = map(int, min_leave.split('-'))

        res = 0
        for month in range(a, c):
            res += mp[month]
        res += d - b + 1

        return res

# @lc code=end

