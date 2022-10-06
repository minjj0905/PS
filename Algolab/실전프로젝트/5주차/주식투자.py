import sys

tc = int(sys.stdin.readline())
for _ in range(tc):
  d = int(sys.stdin.readline())
  arr = list(map(int, sys.stdin.readline().split()))
  
  arr.reverse()
  
  max = arr[0]
  profit = 0

  for i in range(1, d):
    if arr[i] > max:
      max = arr[i]
    else:
      profit += max - arr[i]

  sys.stdout.write(str(profit) + '\n')