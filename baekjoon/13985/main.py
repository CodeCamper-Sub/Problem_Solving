import sys, functools, math
sys.setrecursionlimit(10**6)
input = sys.stdin.readline
print = sys.stdout.write

def main():
    a, _, b, _, c = input().split()
    a, b, c = map(int, [a, b, c])
    if a + b == c:
        print("YES")
    else:
        print("NO")
    return

if __name__ == "__main__":
    main()
