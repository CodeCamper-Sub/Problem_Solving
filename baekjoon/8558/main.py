import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline
print = sys.stdout.write

def fact(n):
    if n == 0:
        return 1
    return n * fact(n - 1)

def main():
    print(f"{fact(int(input())) % 10}")
    return

if __name__ == "__main__":
    main()
