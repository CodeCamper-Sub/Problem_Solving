import sys
from functools import reduce
sys.setrecursionlimit(10**6)
input = sys.stdin.readline
print = sys.stdout.write

o = list(map(int, open(0)))
all_same = True
all_different = True
for i in range(1, len(o)):
    if(o[i] != o[i - 1]):
        all_same = False
    if(o[i] == o[i - 1]):
        all_different = False
if all_same:
    print("Fish At Constant Depth\n")
elif not all_different:
    print("No Fish\n")
elif o == sorted(o):
    print("Fish Rising\n")
elif o == sorted(o, reverse=True):
    print("Fish Diving\n")
else:
    print("No Fish\n")
