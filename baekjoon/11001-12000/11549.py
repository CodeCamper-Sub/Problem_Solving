import sys, functools, math
sys.setrecursionlimit(10**6)
input = sys.stdin.readline
print = sys.stdout.write

def main():
    t = int(input())
    print(f"{functools.reduce(lambda a, b: a + b, map(lambda a: a == t, map(int, input().split())))}\n")
    return

if __name__ == "__main__":
    main()
