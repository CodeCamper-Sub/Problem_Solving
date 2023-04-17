import sys, functools, math
sys.setrecursionlimit(10**6)
input = sys.stdin.readline
print = sys.stdout.write

def main():
    a, b = map(int, input().split())
    c = int(input().rstrip())
    if a + b >= 2 * c:
        print(f"{a + b - 2 * c}\n")
    else:
        print(f"{a + b}\n")
    return

if __name__ == "__main__":
    main()
