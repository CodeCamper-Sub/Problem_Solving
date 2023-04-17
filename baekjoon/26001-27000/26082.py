import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline

a, b, c = map(int, input().split())
print(b * c // a * 3)
