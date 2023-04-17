import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline
print = sys.stdout.write

def main():
    k, n, m = map(int, input().split())
    print(f"{max(0, k * n - m)}\n")
    return

if __name__ == "__main__":
    main()
