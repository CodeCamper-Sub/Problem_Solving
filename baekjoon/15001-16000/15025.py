import sys, functools, math
sys.setrecursionlimit(10**6)
input = sys.stdin.readline
print = sys.stdout.write

def main():
    a, b = map(int, input().split())
    if a == 0 and b == 0:
        print("Not a moose")
    elif a == b:
        print(f"Even {a * 2}")
    else:
        print(f"Odd {max(a, b) * 2}")
    return

if __name__ == "__main__":
    main()
