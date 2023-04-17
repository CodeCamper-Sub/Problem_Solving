import sys, functools, math
sys.setrecursionlimit(10**6)
input = sys.stdin.readline
print = sys.stdout.write

def main():
    a = list(map(int, input().split()))
    x, y, r = map(int, input().split())
    for i in range(len(a)):
        if(a[i] == x):
            print(f"{i + 1}\n")
            return
    print(f"0\n")
    return

if __name__ == "__main__":
    main()
