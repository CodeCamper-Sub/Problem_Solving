import sys, functools, math
sys.setrecursionlimit(10**6)
input = sys.stdin.readline
print = sys.stdout.write

def main():
    p1, s1 = map(int, input().split())
    s2, p2 = map(int, input().split())
    if p1 + p2 == s1 + s2:
        if p2 < s1:
            print("Esteghlal")    
        elif p2 > s1:
            print("Persepolis")
        else:    
            print("Penalty")
    elif p1 + p2 < s1 + s2:
        print("Esteghlal")
    else:
        print("Persepolis")
    return

if __name__ == "__main__":
    main()
