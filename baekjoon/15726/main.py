import sys, functools, math
sys.setrecursionlimit(10**6)
input = sys.stdin.readline
print = sys.stdout.write

def main():
    a, b, c = map(int, input().split())
    a *= max(b, c)
    a /= min(b, c)
    print(f"{math.floor(a):.0f}")
    return

if __name__ == "__main__":
    main()
