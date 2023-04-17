import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline
print = sys.stdout.write

for _ in range(3):
    a, b, c, d, e, f = map(int, input().split())
    start = a * 3600 + b * 60 + c
    end = d * 3600 + e * 60 + f
    result = end - start

    h = result // 3600
    result %= 3600
    m = result // 60
    result %= 60
    s = result
    print(f"{h} {m} {s}\n")

