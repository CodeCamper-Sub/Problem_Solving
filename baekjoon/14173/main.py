import sys, functools, math
sys.setrecursionlimit(10**6)
input = sys.stdin.readline
print = sys.stdout.write

def main():
    r1 = list(map(int, input().split()))
    r2 = list(map(int, input().split()))
    s = []
    for i in range(2):
        s.append(min(r1[i], r2[i]))
    for i in range(2):
        s.append(max(r1[i + 2], r2[i + 2]))
    l = max(abs(s[2] - s[0]), abs(s[3] - s[1]))
    print(f"{l * l}\n")
    return

if __name__ == "__main__":
    main()
