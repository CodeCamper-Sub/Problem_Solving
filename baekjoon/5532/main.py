import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline
print = sys.stdout.write

l = int(input())
a = int(input())
b = int(input())
c = int(input())
d = int(input())
print(f"{l - max(a // c + [1, 0][a % c == 0], b // d + [1, 0][b % d == 0])}")
