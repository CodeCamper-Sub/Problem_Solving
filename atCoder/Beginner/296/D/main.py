import sys
import math
sys.setrecursionlimit(10**6)
input = sys.stdin.readline
print = sys.stdout.write

n, m = map(int, input().split())

def has_divider(k, n):
    t = math.ceil(math.sqrt(k))
    while t >= 1 and k // t <= n:
      if k % t == 0:
          return True
      t -= 1
    return False

k = m
has_answer = False
while k <= n * n:
    if has_divider(k, n):
        print(f"{k}\n")
        has_answer = True
        break
    k += 1
if not has_answer:
    print(f"{-1}\n")
