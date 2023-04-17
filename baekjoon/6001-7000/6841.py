import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline
print = sys.stdout.write

def main():
    a = dict()
    a["CU"] = "see you"
    a[":-)"] = "I’m happy"
    a[":-("] = "I’m unhappy"
    a[";-)"] = "wink"
    a[":-P"] = "stick out my tongue"
    a["(~.~)"] = "sleepy"
    a["TA"] = "totally awesome"
    a["CCC"] = "Canadian Computing Competition"
    a["CUZ"] = "because"
    a["TY"] = "thank-you"
    a["YW"] = "you’re welcome"
    a["TTYL"] = "talk to you later"

    while True:
        b = input().rstrip()
        if not b:
            return
        if b in a:
            print(f"{a[b]}\n")
        else:
            print(f"{b}\n")

    return

if __name__ == "__main__":
    main()
