import random
import time

def change_sort(a, n):
    for i in range(n - 1):
        idx = i
        for j in range(i + 1, n):
            if a[j] < a[idx]: idx = j
        a[i], a[idx] = a[idx], a[i]

def main():
    n = int(input())
    a = [random.randint(-1000, 1000) for i in range(n)]
    start = time.perf_counter() 
    change_sort(a, n)
    end = time.perf_counter()

    for i in range(n):
        print(a[i], end = ' ')
        if (i + 1) % 10 == 0: print()

    print('\nRunning time: %.6f ms\n' % ((end - start) * 1000))

if __name__ == "__main__":
    main()