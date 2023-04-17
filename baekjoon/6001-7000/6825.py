import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline
print = sys.stdout.write

def main():
    w, h = map(float, open(0))
    b = w / (h * h)
    if b > 25:
        print("Overweight\n")
    elif b >= 18.5:
        print("Normal weight\n")
    else:
        print("Underweight\n")
    return

if __name__ == "__main__":
    main()
