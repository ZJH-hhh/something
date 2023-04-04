#
# @lc app=leetcode.cn id=901 lang=python3
#
# [901] 股票价格跨度
#

# @lc code=start
from cmath import inf


class StockSpanner:

    def __init__(self):
        self.stk = [(-1, inf)]
        self.idx = -1
        return None  


    def next(self, price: int) -> int:
        self.idx += 1
        while self.stk[-1][1] <= price:
            self.stk.pop()
        self.stk.append((self.idx, price))
        return self.idx - self.stk[-2][0]


# Your StockSpanner object will be instantiated and called as such:
# obj = StockSpanner()
# param_1 = obj.next(price)
# @lc code=end

