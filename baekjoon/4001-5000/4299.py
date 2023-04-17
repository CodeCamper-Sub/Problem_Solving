import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline
print = sys.stdout.write

a, b = map(int, input().split())

if (a + b) % 2:
    print("-1")
else:
  c = (a + b) // 2  
  d = a - c
  if d < 0:
     print("-1")
  else:
    e = sorted([c, d], reverse=True)
    e = map(str, e)
    print(' '.join(e))
