import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline
print = sys.stdout.write

def main():
    for i in range(1, int(input()) + 1):
        print(f"Hello World, Judge {i}!\n")
    return

if __name__ == "__main__":
    main()
