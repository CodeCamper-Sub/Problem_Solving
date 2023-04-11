import sys, functools, math
sys.setrecursionlimit(10**6)
input = sys.stdin.readline
print = sys.stdout.write

def main():
    d1, d2 = map(float, open(0))
    pi = 3.141592
    print(f"{2 * d1 + 2 * d2 * pi:.6f}")
    return

if __name__ == "__main__":
    main()
