import sys, functools, math
sys.setrecursionlimit(10**6)
input = sys.stdin.readline
print = sys.stdout.write

def main():
    a, b, c, d = map(int, open(0))
    if a in [8, 9] and d in [8, 9] and b == c:
        print("ignore")
    else:
        print("answer")
    return

if __name__ == "__main__":
    main()
