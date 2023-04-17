import sys, functools, math
sys.setrecursionlimit(10**6)
input = sys.stdin.readline
print = sys.stdout.write

def main():
    s = input()
    if s[0] == '5' and s[1] == '5' and s[2] == '5':
        print("YES")
    else:
        print("NO")
    return

if __name__ == "__main__":
    main()
