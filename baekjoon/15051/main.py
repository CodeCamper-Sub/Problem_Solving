import sys, functools, math
sys.setrecursionlimit(10**6)
input = sys.stdin.readline
print = sys.stdout.write

def main():
    a, b, c = map(int, open(0))
    print(f"{min(min((2 * a + b) * 2, (b + 2 * c) * 2), (a + c) * 2)}")
    return

if __name__ == "__main__":
    main()
