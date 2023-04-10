import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline
print = sys.stdout.write

def main():
    a, b, c = sorted(list(map(int, input().split())))
    if a == b and b == c:
        print("2")
    elif a * a + b * b == c * c:
        print("1")
    else:
        print("0")
    return

if __name__ == "__main__":
    main()
