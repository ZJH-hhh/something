#
# @lc app=leetcode.cn id=650 lang=python3
#
# [650] 只有两个键的键盘
#

# @lc code=start

"""
对一次copy和x次paste操作可以让原本个数变为x+1倍
对起始长度为1的字符串,进行1次copy和k1-1次paste后长度变为k1,总操作次数k1
对长度为k1的字符串,进行1次copy和k2-1次paste后长度变为k1*k2,总操作次数k1+k2
...
在进行总的k次操作后变为长度n
n=k1*k2*k3*...*kx,总操作次数为k1+k2+...+kx

对于任意ki(合数)而言,a*b >= a+b,
所以我们让每个ki都是质数得到的解一定是最优的
就可以分解n的质因数加起来即可
"""

class Solution:
    def minSteps(self, n: int) -> int:
        res = 0 
        i = 2
        while i <= n // i:
            while n % i == 0:
                res += i
                n //= i
            i += 1
        if n != 1: res += n

        return res

# @lc code=end

