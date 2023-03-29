import sys
while True:
  [a, b, c] = sorted(list(map(int, sys.stdin.readline().split())))
  if a == 0 and b == 0 and c == 0:
    break
  if a + b <= c:
    print("Invalid")
  elif a == b and b == c:
    print("Equilateral")
  elif a != b and b != c and c != a:
    print("Scalene")
  else:
    print("Isosceles")