import sys, functools, math
sys.setrecursionlimit(10**6)
input = sys.stdin.readline
print = sys.stdout.write

def main():
    n, a, b, c, d = map(int, input().split())
    print(f"{min((n // a + [0, 1][n % a != 0]) * b, (n // c + [0, 1][n % c != 0]) * d)}\n")
    return

if __name__ == "__main__":
    main()
