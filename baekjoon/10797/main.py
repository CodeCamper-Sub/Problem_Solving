import sys, functools, math
sys.setrecursionlimit(10**6)
input = sys.stdin.readline
print = sys.stdout.write

def main():
    n = int(input())
    answer = functools.reduce(lambda a, b: a + b, list(map(lambda a: a == n, map(int, input().split()))))
    print(f"{answer}\n")
    return

if __name__ == "__main__":
    main()
