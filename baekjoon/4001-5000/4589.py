import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline
print = sys.stdout.write

print("Gnomes:\n")
for _ in range(int(input())):
    original = list(map(int, input().split()))
    if original == sorted(original) or original == sorted(original, reverse=True):
        print("Ordered\n")
    else:
        print("Unordered\n")
