import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline
print = sys.stdout.write

def main():
    l, r = map(int, open(0))
    while l <= r:
        print(f"All positions change in year {l}\n")
        l += 60
    return

if __name__ == "__main__":
    main()
