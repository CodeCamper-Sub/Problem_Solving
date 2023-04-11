import sys, functools, math
sys.setrecursionlimit(10**6)
input = sys.stdin.readline
print = sys.stdout.write

def main():
    for i in range(int(input())):
        print(f"Data Set {i + 1}:\n")
        n, s, d = map(int, input().split())
        answer = 0
        for _ in range(n):
            di, v = map(int, input().split())
            if di <= s * d:
                answer += v
        print(f"{answer}\n\n")
    return

if __name__ == "__main__":
    main()
