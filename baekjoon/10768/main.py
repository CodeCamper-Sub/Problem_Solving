import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline
print = sys.stdout.write

def main():
    m, d = map(int, open(0))
    if m < 2:
        print("Before")
    elif m > 2:
        print("After")
    elif d < 18:
        print("Before")
    elif d > 18:
        print("After")
    else:
        print("Special")
    return

if __name__ == "__main__":
    main()
