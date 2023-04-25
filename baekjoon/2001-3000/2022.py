import sys, functools, math
input = sys.stdin.readline
print = sys.stdout.write

def main():
    x, y, c = map(float, input().split())
    left = 0
    right = min(x, y)
    right = math.ceil(right)
    while left <= right:
      mid = (left + right) / 2
      result = math.sqrt((x * x - mid * mid) * (y * y - mid * mid)) / (math.sqrt(x * x - mid * mid) + math.sqrt(y * y - mid * mid))
      if result <= c:
        right = mid - 0.0001
      else:
        left = mid + 0.0001
    print(f"{right:.3f}\n")
    return

if __name__ == "__main__":
    main()
