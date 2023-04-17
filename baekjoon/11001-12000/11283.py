import sys, functools, math
sys.setrecursionlimit(10**6)
input = sys.stdin.readline
print = sys.stdout.write

def main():
    a = input().rstrip()
    print(f"{ord(a) - ord('가') + 1}\n")
    return

if __name__ == "__main__":
    main()
