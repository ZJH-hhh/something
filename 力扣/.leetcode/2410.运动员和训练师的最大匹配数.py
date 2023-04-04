#
# @lc app=leetcode.cn id=2410 lang=python3
#
# [2410] 运动员和训练师的最大匹配数
#

# @lc code=start
class Solution:
    def matchPlayersAndTrainers(self, players: List[int], trainers: List[int]) -> int:
        players.sort()
        trainers.sort()
        
        n, m = len(players), len(trainers)
        i = j = 0
        res = 0
        while i < n and j < m:
            while j < m and players[i] > trainers[j]: j += 1
            if j < m: res += 1
            i, j = i + 1, j + 1

        return res

# @lc code=end
