import sys, functools, math
sys.setrecursionlimit(10**6)
input = sys.stdin.readline
print = sys.stdout.write

def main():
    a = ["YONSEI", "Leading the Way to the Future"][int(input().rstrip())]
    print(f"{a}")
    return

if __name__ == "__main__":
    main()
