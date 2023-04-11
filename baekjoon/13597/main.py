import sys, functools, math
sys.setrecursionlimit(10**6)
input = sys.stdin.readline
print = sys.stdout.write

def main():
    a, b = map(int, input().split())
    if a == b:
        print(f"{a}")
    else:
        print(f"{max(a, b)}")
    return

if __name__ == "__main__":
    main()
