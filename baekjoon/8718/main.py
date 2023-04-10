import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline
print = sys.stdout.write

def main():
    x, k = map(int, input().split())
    x *= 1000
    k *= 1000
    if 7 * k <= x:
        print(f"{7 * k}")
    elif 3.5 * k <= x:
        print(f"{3.5 * k:.0f}")
    elif 1.75 * k <= x:
        print(f"{1.75 * k:.0f}")
    else:
        print("0")

    return

if __name__ == "__main__":
    main()
