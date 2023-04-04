import time
import sys
import os

c = [[0 for j in range(30)] for i in range(30)]

# 初始化组合数
def init():
    for i in range(30):
        for j in range(i + 1):
            if not j: c[i][j] = 1
            else: c[i][j] = c[i - 1][j] + c[i - 1][j - 1]

# 计算长度小于s的个数
def minlen_sum(s):
    res = 0
    for i in range(1, len(s)):
        res += c[26][i]
    return res

# 计算长度等于s的前面的个数
def equallen_sum(s):
    res, pre, length = 0, -1, len(s)
    for i in range(length):
        cur = ord(s[i]) - ord('a') # 取得当前字符
        for j in range(pre + 1, cur):
            res += c[26 - j - 1][length - i - 1]
        pre = cur
    return res

# 判断字符串s是否严格升序
def check(s):
    for i in range(len(s) - 1):
        for j in range(i + 1, len(s)):
            if s[i] >= s[j]: return False
    return True

def solve(s):
    if not check(s): 
        print(0)
        return 
    sum = 0
    sum += minlen_sum(s)
    sum += equallen_sum(s)
    print(sum + 1)

def main():
    sys.stdin = open('ENCODE.in', 'r')
    start = time.perf_counter()

    n = int(input())
    
    init()

    while n:
        s = input()
        solve(s)
        n -= 1
        
    end = time.perf_counter()
    print("Running time: %.6f ms" % ((end - start) * 1000))

if __name__ == "__main__":
    main()