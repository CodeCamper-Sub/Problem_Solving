import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline
print = sys.stdout.write

a, b = map(int, open(0))
print(f"{b + (b - a)}\n")
