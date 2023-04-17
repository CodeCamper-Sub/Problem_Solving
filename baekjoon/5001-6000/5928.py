import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline
print = sys.stdout.write

start = 11 * 24 * 60 + 11 * 60 + 11
d, h, w = map(int, input().split())
end = d * 24 * 60 + h * 60 + w

if end < start:
    print("-1\n")
else:
    print(f"{end - start}\n")
