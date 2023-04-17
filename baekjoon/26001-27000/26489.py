import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline
print = sys.stdout.write

for i in range(1100000000000000):
    if(input() == ""):
        print(f"{i}")
        break