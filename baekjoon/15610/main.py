import sys, functools, math
sys.setrecursionlimit(10**6)
input = sys.stdin.readline
print = sys.stdout.write

def main():
    print(f"{math.sqrt(float(input().rstrip())) * 4:.9f}")
    return

if __name__ == "__main__":
    main()
