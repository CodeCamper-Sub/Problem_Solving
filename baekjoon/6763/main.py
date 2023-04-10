import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline
print = sys.stdout.write

a, b = map(int, open(0))

if a >= b:
    print("Congratulations, you are within the speed limit!\n")
elif a + 20 >= b:
    print("You are speeding and your fine is $100.")
elif a + 30 >= b:
    print("You are speeding and your fine is $270.")
else:
    print("You are speeding and your fine is $500.")
