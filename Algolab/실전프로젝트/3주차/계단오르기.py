import sys

t = int(sys.stdin.readline())

for i in range(t):
  n, p = map(int, sys.stdin.readline().split())

  a = p-1 
  b = n - (p+1)

  jump_a = a // 2 + 1 if a%2 else a // 2
  jump_b = b // 2 + 1 if b%2 else b // 2

  sys.stdout.write(str(jump_a+jump_b+1)+ "\n") 
