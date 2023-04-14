import sys, functools, math
sys.setrecursionlimit(10**6)
input = sys.stdin.readline
print = sys.stdout.write

def main():
    n = (int(input()) - 1) % 8
    n += 1
    if n <= 5:
        print(f"{n}")
    else:
        print(f"{10 - n}")
    return

if __name__ == "__main__":
    main()
