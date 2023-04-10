import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline
print = sys.stdout.write

def main():
    for _ in range(int(input())):
        w, k = map(int, input().split())
        if w % 2 == 0:
            print(f"{w // 2 * k}\n")
        elif k % 2 == 0:
            print(f"{k // 2 * w}\n")
        else:
            print(f"{w // 2 * k + k // 2}\n")
    return

if __name__ == "__main__":
    main()
