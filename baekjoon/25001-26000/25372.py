import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline
print = sys.stdout.write

for _ in range(int(input())):
    pw = input().rstrip()
    if len(pw) >= 6 and len(pw) <= 9:
        print("yes\n")
    else:
        print("no\n")
