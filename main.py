# for i in range(-7, 4):
#   for j in range(-7, 4):
#     for k in range(-3, 8):
#       for l in range(-3, 8):
#         list = [i, j, k, l]
#         is_possible = True
#         for m in range(0, 4):
#           for n in range(m + 1, 4):
#             sum = 0
#             for o in range(0, 4):
#               if o != m and o != n:
#                 sum += list[o]
#             if sum != list[m] * list[n]:
#               is_possible = False
#               break
#           if not is_possible:
#             break
#         if is_possible:
#           print(f"{list}")

for i in range(-6, 6):
  for j in range(-6 ,6):
    for k in range(-6, 6):
      for l in range(-6, 6):
        for m in range(-6, 6):
          for n in range(-6, 6):
            list = [i, j, k, l, m, n]
            is_possible = True
            for o in range(0, 6):
              for p in range(o, 6):
                for q in range(p, 6):
                  sum = 0
                  for r in range(0, 6):
                    if r != o and r != p and r != q:
                      sum += list[r]
                  if sum != list[o] * list[p] * list[q]:
                    is_possible = False
                    break
                if not is_possible:
                  break
              if not is_possible:
                  break;
            if is_possible:
              print(f"{list}")
