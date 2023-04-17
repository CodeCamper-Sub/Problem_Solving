import sys, functools, math
sys.setrecursionlimit(10**6)
input = sys.stdin.readline
print = sys.stdout.write

def main():
    for _ in range(int(input())):
        a, b = input().split()
        if a == b:
            print("OK\n")
        else:
            print("ERROR\n")
    return

if __name__ == "__main__":
    main()
