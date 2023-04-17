import sys, functools, math
sys.setrecursionlimit(10**6)
input = sys.stdin.readline
print = sys.stdout.write

def main():
    a, b, c, d, e, f = map(int, open(0))
    g = sorted([a, b, c, d])
    answer = g[1] + g[2] + g[3]
    answer += sorted([e, f])[1]
    print(f"{answer}\n")
    return

if __name__ == "__main__":
    main()
