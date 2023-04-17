import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline
print = sys.stdout.write

t, s = map(int, input().split())
if t <= 11 or t >= 17 or s == 1:
    print("280")
else:
    print("320")

