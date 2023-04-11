import sys, functools, math
sys.setrecursionlimit(10**6)
input = sys.stdin.readline
print = sys.stdout.write

def main():
    r, c = map(int, input().split())
    grid = []
    for _ in range(r):
        grid.append(input().rstrip())
    for i in range(r):
        for j in range(c):
            print(f"{grid[i][c - j - 1]}")
        print("\n")
    return

if __name__ == "__main__":
    main()
