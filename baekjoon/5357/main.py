import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline
print = sys.stdout.write

for _ in range(int(input())):
    s = input().rstrip()
    for i in range(len(s)):
        if i == 0 or s[i] != s[i - 1]:
            print(s[i])
    print("\n")
