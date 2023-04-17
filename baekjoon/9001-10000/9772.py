import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline
print = sys.stdout.write

def main():
    while True:
        x, y = map(float, input().split())
        if x == 0 and y == 0:
            print("AXIS\n")
            return
        elif x == 0 or y == 0:
            print("AXIS\n")
        elif x > 0 and y > 0:
            print("Q1\n")
        elif x < 0 and y > 0:
            print("Q2\n")
        elif x < 0 and y < 0:
            print("Q3\n")
        else:
            print("Q4\n")
    return

if __name__ == "__main__":
    main()
