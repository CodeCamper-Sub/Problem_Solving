import sys
from functools import reduce
sys.setrecursionlimit(10**6)
input = sys.stdin.readline
print = sys.stdout.write

print(f"{max(reduce(lambda acc, cur: acc + cur, list(map(int, input().split())), 0), reduce(lambda acc, cur: acc + cur, list(map(int, input().split())), 0))}")


