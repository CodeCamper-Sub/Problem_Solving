import sys, functools, math
sys.setrecursionlimit(10**6)
input = sys.stdin.readline
print = sys.stdout.write

def main():
    h, _, m, _, s = input().split()
    hh, _, mm, _, ss = input().split()
    [h, m, s, hh, mm, ss] = map(int, [h, m, s, hh, mm, ss])
    f = h * 3600 + m * 60 + s
    t = hh * 3600 + mm * 60 + ss
    if f <= t:
        print(f"{t - f}\n")
    else:
        print(f"{24 * 3600 + t - f}\n")
    return

if __name__ == "__main__":
    main()
