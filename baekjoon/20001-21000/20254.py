import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline
print = sys.stdout.write

a, b, c, d = map(int, input().split())

print(str(56 * a + 24 * b + 14 * c + 6 * d))
