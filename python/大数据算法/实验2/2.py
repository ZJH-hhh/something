import random
import time

def bubble_sort(a, n):
    for i in range(1, n):
        for j in range(0, n - i):
            if a[j] > a[j + 1]:
                a[j], a[j + 1] = a[j + 1], a[j]

def main():
    n = int(input())
    a = [random.randint(-1000, 1000) for i in range(n)]
    start = time.perf_counter() 
    bubble_sort(a, n)
    end = time.perf_counter()

    for i in range(n):
        print(a[i], end = ' ')
        if (i + 1) % 10 == 0: print()

    print('\nRunning time: %.6f ms\n' % ((end - start) * 1000))

if __name__ == "__main__":
    main()