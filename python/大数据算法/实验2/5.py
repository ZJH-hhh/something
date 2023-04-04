import random

def quick_sort(l, r, a):
    if (l >= r): return 
    x = a[l + r >> 1]
    i, j = l - 1, r + 1
    while i < j:
        while True:
            i += 1
            if (a[i] >= x): break
        while True:
            j -= 1
            if (a[j] <= x): break
        if i < j: a[i], a[j] = a[j], a[i]

    quick_sort(l, j, a), quick_sort(j + 1, r, a)
        

def main():
    n = int(input())
    a = [random.randint(-1000, 1000) for i in range(n)]

    quick_sort(0, n - 1, a)

    for i in range(n):
        print(a[i], end = ' ')
        if (i + 1) % 10 == 0: print()

if __name__ == "__main__":
    main()