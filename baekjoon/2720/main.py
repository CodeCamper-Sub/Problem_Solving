import sys

for _ in range(int(input())):
  c = int(input())
  q = c // 25
  c %= 25
  d = c // 10
  c %= 10
  n = c // 5
  c %= 5
  p = c // 1
  print(f"{q} {d} {n} {p}")