import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline
print = sys.stdout.write

for _ in range(int(input())):
    a = input().rstrip()
    print(f"{a} {a}\n")
