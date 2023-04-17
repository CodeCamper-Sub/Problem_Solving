import sys, functools, math
sys.setrecursionlimit(10**6)
input = sys.stdin.readline
print = sys.stdout.write

def main():
    a, b, c, d = map(int, input().split())
    print(f"{[0, 1][(a * c) % (b * d * 2) == 0]}")
    return

if __name__ == "__main__":
    main()
