import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline
print = sys.stdout.write

a = list(map(int, input().split()))
a.sort()

print(' '.join(str(a) for a in a))
