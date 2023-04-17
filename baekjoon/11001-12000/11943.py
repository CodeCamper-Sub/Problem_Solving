import sys, functools, math
sys.setrecursionlimit(10**6)
input = sys.stdin.readline
print = sys.stdout.write

def main():
    a, b = map(int, input().split())
    c, d = map(int ,input().split())
    print(f"{min(a + d, b + c)}\n")
    return

if __name__ == "__main__":
    main()
