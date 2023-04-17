import sys, functools, math
sys.setrecursionlimit(10**6)
input = sys.stdin.readline
print = sys.stdout.write

def main():
    a, b, c, d = map(int, input().split())
    print(f"{abs(a + d - b - c)}")
    return

if __name__ == "__main__":
    main()
