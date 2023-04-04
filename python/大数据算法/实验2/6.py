import random

n = int(input())
a = [0 for i in range(n + 5)]

def down(u):
    t = u
    if u * 2 <= n and a[u * 2] < a[t]: t = u * 2
    if u * 2 + 1 <= n and a[u * 2 + 1] < a[t]: t = u * 2 + 1
    if t != u:
        a[t], a[u] = a[u], a[t]
        down(t)

def main():
    for i in range(1, n + 1):
        a[i] = random.randint(-1000, 1000)

    for i in range(n // 2, 0, -1): down(i)

    size = n
    for i in range(n):
        print(a[1], end = ' ')
        if (i + 1) % 10 == 0: print()
        a[1] = a[size]
        size -= 1
        down(1)

if __name__ == "__main__":
    main()