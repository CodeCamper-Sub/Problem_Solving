import sys

n = int(sys.stdin.readline())
answer = 0
for i in range(1, 2100000000):
  if i * i > n:
    break
  answer += 1
print(answer)
