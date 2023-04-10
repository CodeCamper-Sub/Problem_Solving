import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline
print = sys.stdout.write

def main():
    a, e = map(int, open(0))
    if a >= 3 and e <= 4:
        print("TroyMartian\n")
    if a <= 6 and e >= 2:
        print("VladSaturnian\n")
    if a <= 2 and e <= 3:
        print("GraemeMercurian\n")
    return

if __name__ == "__main__":
    main()
