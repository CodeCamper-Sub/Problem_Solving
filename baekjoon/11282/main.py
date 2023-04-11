import sys, functools, math
sys.setrecursionlimit(10**6)
input = sys.stdin.readline
print = sys.stdout.write

def main():
    n = int(input())
    print(f"{chr(ord('가') + n - 1)}\n")
    return

if __name__ == "__main__":
    main()
