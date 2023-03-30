import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline
print = sys.stdout.write

n = int(input())
for _ in range(n // 5):
    print("V")
for _ in range(n % 5):
    print("I")