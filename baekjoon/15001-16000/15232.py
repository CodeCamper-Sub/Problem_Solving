import sys, functools, math
sys.setrecursionlimit(10**6)
input = sys.stdin.readline
print = sys.stdout.write

def main():
    r, c = map(int, open(0))
    for _ in range(r):
        for _ in range(c):
            print("*")
        print("\n")
    return

if __name__ == "__main__":
    main()
