import sys, functools, math
sys.setrecursionlimit(10**6)
input = sys.stdin.readline
print = sys.stdout.write

def main():
    a = list(map(lambda a: ord(a) - ord('0'), list(input().rstrip())))
    if len(a) == 4:
        print("20\n")
    elif len(a) == 2:
        print(f"{a[0] + a[1]}")
    else:
        if a[0] == 1 and a[1] == 0:
            print(f"{a[2] + 10}")
        else:
            print(f"{a[0] + 10}")
    return

if __name__ == "__main__":
    main()
