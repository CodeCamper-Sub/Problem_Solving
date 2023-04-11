import sys
from functools import reduce
sys.setrecursionlimit(10**6)
input = sys.stdin.readline
print = sys.stdout.write

def change(n):
    if n < 40:
        return 40
    else:
        return n

def main():
    n = reduce(lambda a, b: a + b, list(map(change, map(int, open(0)))), 0) // 5

    print(f"{n}\n")
    return

if __name__ == "__main__":
    main()
