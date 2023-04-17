import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline
print = sys.stdout.write

n = int(input())
print(f"{n // 100 * 78} {(n // 100 * 80) + (n // 100 * 20 // 100 * 78)}")
