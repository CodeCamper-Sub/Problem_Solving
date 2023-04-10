import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline
print = sys.stdout.write

def main():
    while True:
        n = int(input())
        if not n:
            break
        for i in range(1, n + 1):
            for _ in range(i):
                print("*")
            print("\n")
    return

if __name__ == "__main__":
    main()
