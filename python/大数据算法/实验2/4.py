import time
import random

def insert_sort(a, n):
    for i in range(1, n):
        l, r, x = 0, i - 1, a[i]
        while l < r:
            mid = l + r + 1 >> 1
            if a[mid] <= x: l = mid
            else: r = mid - 1
        
        for j in range(i, l, -1): a[j] = a[j - 1]
        a[l] = x

def main():
    n = int(input())
    a = [random.randint(-1000, 1000) for i in range(n)]
    # a = [1, 3, 5, 7, 9, 4]
    # n = 6
    start = time.perf_counter() 
    insert_sort(a, n)
    end = time.perf_counter()

    for i in range(n):
        print(a[i], end = ' ')
        if (i + 1) % 10 == 0: print()

    print('\nRunning time: %.6f ms\n' % ((end - start) * 1000))

if __name__ == "__main__":
    main()