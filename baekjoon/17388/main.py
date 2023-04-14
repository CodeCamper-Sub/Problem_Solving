import sys, functools, math
sys.setrecursionlimit(10**6)
input = sys.stdin.readline
print = sys.stdout.write
def min3(a, b, c):
    return min(a, min(b, c))

def main():
    s, k, h = map(int, input().split())
    if s + k + h >= 100:
        print("OK")
    elif min3(s, k, h) == s:
        print("Soongsil")
    elif min3(s, k, h) == k:
        print("Korea")
    else:
        print("Hanyang")
    return

if __name__ == "__main__":
    main()
