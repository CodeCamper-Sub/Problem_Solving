import sys

def recursive(n):
  if n == 1:
    return "-"
  else:
    return recursive(n // 3) + ''.join([' ' for _ in range(n // 3)]) + recursive(n // 3)



while True:
  try:
    n = int(input())
    print(recursive(pow(3, n)))

  except EOFError:
    break