import sys, functools, math
sys.setrecursionlimit(10**6)
input = sys.stdin.readline
print = sys.stdout.write

def main():
    for _ in range(int(input())):
        n = int(input())
        if n % 2 == 0:
            print(f"{n} is even\n")
        else:
            print(f"{n} is odd\n")

    return

if __name__ == "__main__":
    main()
