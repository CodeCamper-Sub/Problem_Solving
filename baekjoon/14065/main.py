import sys, functools, math
sys.setrecursionlimit(10**6)
input = sys.stdin.readline
print = sys.stdout.write

def main():
    a = float(input().rstrip())
    a = 1 / (a * 1.609344 / 3.785411784 / 100)
    print(f"{a:.6f}")
    return

if __name__ == "__main__":
    main()
