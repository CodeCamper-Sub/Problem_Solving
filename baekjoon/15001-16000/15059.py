import sys, functools, math
sys.setrecursionlimit(10**6)
input = sys.stdin.readline
print = sys.stdout.write

def main():
    a, b, c = map(int, input().split())
    d, e, f = map(int, input().split())
    print(f"{max(0, d - a) + max(0, e - b) + max(0, f - c)}")
    return

if __name__ == "__main__":
    main()
