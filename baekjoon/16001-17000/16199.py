import sys, functools, math
sys.setrecursionlimit(10**6)
input = sys.stdin.readline
print = sys.stdout.write

def main():
    y, m, d = map(int, input().split())
    yy, mm, dd = map(int, input().split())

    if m < mm or (m == mm and d <= dd):
        print(f"{yy - y}\n")
    else:
        print(f"{yy -y - 1}\n")
    print(f"{yy - y + 1}\n")
    print(f"{yy - y}\n")
    return

if __name__ == "__main__":
    main()
