import sys, functools, math
sys.setrecursionlimit(10**6)
input = sys.stdin.readline
print = sys.stdout.write

def main():
    a1, p1 = map(int, input().split())
    a2, p2 = map(int, input().split())
    a2 = a2 * a2 * math.pi
    if(a1 / p1 > a2 / p2):
        print("Slice of pizza")
    else:
        print("Whole pizza")
    return

if __name__ == "__main__":
    main()
