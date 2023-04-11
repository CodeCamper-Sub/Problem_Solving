import sys, functools, math
sys.setrecursionlimit(10**6)
input = sys.stdin.readline
print = sys.stdout.write

def main():
    for _ in range(int(input())):
        l = list(input().split())
        id = l[0]
        a, b, c = map(float, l[1:])
        if a + b + c >= 55 and a >= 35 * 0.3 and b >= 25 * 0.3 and c >= 40 * 0.3:
            print(f"{id} {int(a + b + c)} PASS\n")
        else:
            print(f"{id} {int(a + b + c)} FAIL\n")

    return

if __name__ == "__main__":
    main()
