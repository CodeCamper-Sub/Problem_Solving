import sys, functools, math
sys.setrecursionlimit(10**6)
input = sys.stdin.readline
print = sys.stdout.write

def main():
    n, m, k = map(int, input().split())
    if m < k:
        print(f"{m + n - k}\n")
    else:
        print(f"{k + n - m}\n")
    return

if __name__ == "__main__":
    main()
