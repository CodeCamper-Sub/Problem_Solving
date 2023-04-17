import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline
print = sys.stdout.write

while True:
    s = list(input().rstrip())
    if not s:
        break
    for i in range(len(s)):
        if s[i] == 'i':
            s[i] = 'e'
        elif s[i] == 'e':
            s[i] = 'i'
        elif s[i] == 'I':
            s[i] = 'E'
        elif s[i] == 'E':
            s[i] = 'I'
    print(''.join(s))
    print('\n')
