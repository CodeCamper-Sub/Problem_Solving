import sys, functools, math
sys.setrecursionlimit(10**6)
input = sys.stdin.readline
print = sys.stdout.write

def main():
    a, b = map(int, input().split())
    if a % 2 == 0:
        answer = a // 2 * b
    elif b % 2 == 0:
        answer = b // 2 * a
    else:
        answer = a // 2 * b + b // 2
    print(f"{answer}")
    return

if __name__ == "__main__":
    main()
