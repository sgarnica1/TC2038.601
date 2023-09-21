def burronacci(n: int) -> int:
  """
  Burronnaci Sequence
  n = 2 * (n - 1) + (n - 2)
  """
  if(n == 0): return 1
  if(n == 1): return 2

  b1 = 1
  b2 = 2

  return ((b2 * 4) + (b1 * 2)) / 2

  

def run():
  next = burronacci(5)

  print(next)


if __name__ == "__main__":
  run()