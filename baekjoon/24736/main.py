import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline
print = sys.stdout.write

for _ in range(2):
    a, b, c, d, e = map(int, input().split())
    print(f"{6 * a + 3 * b + 2 * c + 1 * d + 2 * e} ")
