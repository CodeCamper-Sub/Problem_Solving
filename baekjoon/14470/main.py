import sys, functools, math
sys.setrecursionlimit(10**6)
input = sys.stdin.readline
print = sys.stdout.write

def main():
    a, b, c, d, e = map(int, open(0))
    isFrozen = a < 0
    answer = 0
    while a != b:
        if a < 0:
            answer += c
            a += 1
        elif a == 0 and isFrozen:
            answer += d
            isFrozen = False
        else:
            answer += e
            a += 1

    print(f"{answer}")
    return

if __name__ == "__main__":
    main()
