import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline
print = sys.stdout.write

def main():
    ls = [
    """ * * *
*     *
*     *
*     *

*     *
*     *
*     *
 * * *""",
    """
      *
      *
      *

      *
      *
      *
""",
    """ * * *
      *
      *
      *
 * * *
*
*
*
 * * * """,
    """ * * *
      *
      *
      *
 * * *
      *
      *
      *
 * * *""",
    """
*     *
*     *
*     *
 * * *
      *
      *
      *
""",
    """ * * *
*
*
*
 * * *
      *
      *
      *
 * * *""",
    """ * * *
*
*
*
 * * *
*     *
*     *
*     *
 * * *""",
    """ * * *
      *
      *
      *

      *
      *
      *
""",
    """ * * *
*     *
*     *
*     *
 * * *
*     *
*     *
*     *
 * * *""",
    """ * * *
*     *
*     *
*     *
 * * *
      *
      *
      *
 * * *""",
]
    print(ls[int(input())])
    return

if __name__ == "__main__":
    main()
