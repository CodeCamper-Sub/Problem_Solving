import sys, functools, math
sys.setrecursionlimit(10**6)
input = sys.stdin.readline
print = sys.stdout.write

def main():
    a, b, c = map(int, input().split())
    if a == b and b == c:
        print("*")
    elif a != b and b == c:
        print("A")
    elif a != b and a == c:
        print("B")
    else:
        print("C")
    return

if __name__ == "__main__":
    main()
