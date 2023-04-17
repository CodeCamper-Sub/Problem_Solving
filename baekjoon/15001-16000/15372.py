import sys, functools, math
sys.setrecursionlimit(10**6)
input = sys.stdin.readline
print = sys.stdout.write

def main():
    for _ in range(int(input())):
        n = int(input().rstrip())
        print(f"{n * n}\n")
    return

if __name__ == "__main__":
    main()
