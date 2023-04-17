import sys

[a, b, c] = sorted(list(map(int, sys.stdin.readline().split())))
if a + b > c:
  print(a + b + c)
else:
  print(2 * a + 2 * b - 1)
