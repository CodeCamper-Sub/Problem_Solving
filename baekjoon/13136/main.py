import sys, functools, math
sys.setrecursionlimit(10**6)
input = sys.stdin.readline
print = sys.stdout.write

def main():
    r, c, n = map(int, input().split())
    r = r // n + [1, 0][r % n == 0]
    c = c // n + [1, 0][c % n == 0]
    print(f"{r * c}\n")
    return

if __name__ == "__main__":
    main()
