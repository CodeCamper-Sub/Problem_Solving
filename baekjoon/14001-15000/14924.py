import sys, functools, math
sys.setrecursionlimit(10**6)
input = sys.stdin.readline
print = sys.stdout.write

def main():
    s, t, d = map(int, input().split())
    print(f"{t * (d // (2 * s))}")
    return

if __name__ == "__main__":
    main()
