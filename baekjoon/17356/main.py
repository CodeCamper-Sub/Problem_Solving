import sys, functools, math
sys.setrecursionlimit(10**6)
input = sys.stdin.readline
print = sys.stdout.write

def main():
    a, b = map(int, input().split())
    m = (b - a) / 400
    answer = 1 / (1 + (10**m))
    print(f"{answer:.5f}")
    return

if __name__ == "__main__":
    main()
