import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline
print = sys.stdout.write

def main():
    k, w, m = map(int, input().split())
    print(f"{(w - k) // m + [1, 0][(w - k) % m == 0]}")
    return

if __name__ == "__main__":
    main()
