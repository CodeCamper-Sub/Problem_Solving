import sys
from functools import reduce
sys.setrecursionlimit(10**6)
input = sys.stdin.readline
print = sys.stdout.write

a, b, c, d, e, f = map(int, input().split())
print(f"{(a + b + c+ d + e + f) * 5}")
