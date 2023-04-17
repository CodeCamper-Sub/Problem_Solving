import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline
print = sys.stdout.write

def leading_dot(a):
    if a[0] == '.':
        return '0' + a
    else:
        return a

for _ in range(int(input())):
    a, b, c = map(float, map(lambda a: leading_dot(a), input().rstrip().split()))
    print("${:.2f}\n".format(a * b * c))