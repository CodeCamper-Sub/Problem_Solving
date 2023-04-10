import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline
print = sys.stdout.write

while True:
    n = float(input())
    if n == 0:
        break
    answer = 0
    k = 1
    for _ in range(5):
        answer += k
        k *= n
    print(f"{answer:.2f}\n")
    
