import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline
print = sys.stdout.write

def main():
    for _ in range(int(input())):
        c, r = map(int, input().split())
        for _ in range(r):
            for _ in range(c):
                print("X")
            print("\n")
        print("\n")
    return

if __name__ == "__main__":
    main()
