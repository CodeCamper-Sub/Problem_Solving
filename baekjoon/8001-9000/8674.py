import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline
print = sys.stdout.write

def main():
    a, b = map(int, input().split())
    if a % 2 == 0 or b % 2 == 0:
        print("0\n")
    else:
        print(f"{min(a, b)}")
    return

if __name__ == "__main__":
    main()
