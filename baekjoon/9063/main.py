import sys
n = int(sys.stdin.readline())
minx = 20000
maxx = -20000
miny = 20000
maxy = -20000
for i in range(n):
  x, y = map(int, sys.stdin.readline().split())
  minx = min(minx, x)
  maxx = max(maxx, x)
  miny = min(miny, y)
  maxy = max(maxy, y)
print((maxx-minx) * (maxy - miny))