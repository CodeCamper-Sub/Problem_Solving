import sys, functools, math
sys.setrecursionlimit(10**6)
input = sys.stdin.readline
print = sys.stdout.write

def main():
    [a, b, c] = sorted(list(map(int, input().split())))
    if a == b or b == c or c == a or a + b == c:
        print("S")
    else:
        print("N")
    return

if __name__ == "__main__":
    main()
