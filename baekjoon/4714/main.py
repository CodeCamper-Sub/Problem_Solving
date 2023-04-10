import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline
print = sys.stdout.write

while True:
    n = float(input())
    if n == -1.0:
        break
    print(f"Objects weighing {n:.2f} on Earth will weigh {n*0.167:.2f} on the moon.\n")
