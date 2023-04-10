from math import floor, sqrt
import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline
print = sys.stdout.write

def main():
    a = int(input())
    print(f"The largest square has side length {floor(sqrt(a))}.\n")
    return

if __name__ == "__main__":
    main()
