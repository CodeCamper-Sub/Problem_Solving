import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline
print = sys.stdout.write

def main():
    case = 1
    while True:
        a = list(map(int, input().split()))
        n = a[0]
        if n == 0:
            return
        del(a[0])
        med = 0
        for i in range(n):
            if n % 2 == 0 and (i == n // 2 - 1) or (i == n // 2):
                med += a[i]
            elif n % 2 == 1 and (i == n // 2):
                med += a[i]
        if n % 2 == 0:
            med /= 2
        print(f"Case {case}: {med:.1f}\n")
        case += 1
            
    return

if __name__ == "__main__":
    main()
