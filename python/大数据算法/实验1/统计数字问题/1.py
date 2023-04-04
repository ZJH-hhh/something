import time
import sys
import os

# 计算数x共有多少位
def dgt(x):
    res = 0
    while x:
        res += 1
        x //= 10
    return res

# 返回1~n中数字x出现的次数
def count(n, x):
    res, m = 0, dgt(n)
    # 从右往左枚举第i位上x出现的次数，加起来就是总的x出现的次数
    for i in range(1, m + 1):
        p = 10 ** (i - 1)
        # l是第i位左边的数，r是第i位右边的数，di表示第i位上的数字
        l, r, di = n // p // 10, n % p, n // p % 10

        # 计算从右往左第i位左边的数小于l的情况
        if x: res += l * p 
        elif l: res += (l - 1) * p # x为0，要去除前导零的情况

        # 计算第i位左边等于l的情况
        if di > x and (x or l): res += p
        elif di == x and (x or l): res += r + 1

    return res

def main():
    for i in range(10):
        path = 'TEST/COUNT' + str(i) + '.IN'

        f = open(path, 'r')
        sys.stdin = f

        n = int(input())

        start = time.perf_counter() 

        print("num: %d" % n)
        for i in range(10):
            print(count(n, i), end = ' ')

        end = time.perf_counter() 

        print('\nRunning time: %.6f ms\n' % ((end - start) * 1000))

        f.close()

if __name__ == "__main__":
    main()