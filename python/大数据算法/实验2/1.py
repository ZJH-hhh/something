import random

def main():
    a = [random.randint(-1000, 1000) for i in range(10 ** 5)]
    print(a)

if __name__ == "__main__":
    main()