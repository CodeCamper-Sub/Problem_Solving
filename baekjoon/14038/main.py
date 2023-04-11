import sys, functools, math
sys.setrecursionlimit(10**6)
input = sys.stdin.readline
print = sys.stdout.write

def main():
    w = 0
    for _ in range(6):
        if input().rstrip() == "W":
            w += 1
    if w == 5 or w == 6:
        print("1")
    elif w == 3 or w == 4:
        print("2")
    elif w == 1 or w == 2:
        print("3")
    else:
        print("-1")
    return

if __name__ == "__main__":
    main()
