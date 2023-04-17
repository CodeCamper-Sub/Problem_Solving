import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline
print = sys.stdout.write

def main():
    answer = 9 * 1 + 7 * 3 + 8 * 1 + 0 * 3 + 9 * 1 + 2 * 3 + 1 * 1 + 4 * 3 + 1 * 1 + 8 * 3
    a, b, c = map(int, open(0))
    answer += a * 1 + b * 3 + c * 1
    print(f"The 1-3-sum is {answer}\n")
    return

if __name__ == "__main__":
    main()
