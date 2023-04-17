import sys, functools, math
sys.setrecursionlimit(10**6)
input = sys.stdin.readline
print = sys.stdout.write

def main():
    a, b, c, d, e, f = map(int, open(0))
    sa = a * 3 + b * 2 + c
    sb = d * 3 + e * 2 + f
    if sa == sb:
        print("T")
    elif sa < sb:
        print("B")
    else:
        print("A")
    return

if __name__ == "__main__":
    main()
