import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline
print = sys.stdout.write

n = int(input())
for i in range(1, n + 1):
    print(f"{i} ")
    if i % 6 == 0 and i != n:
        print("Go! ")

print("Go!")
