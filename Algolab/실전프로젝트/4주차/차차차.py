import sys

def search(arr, n, x):
  cnt = 0
  line = arr[0]

  values = []
  value = 0

  # 왼쪽
  if x > 0 and line[x-1] != 1 :
    nx = line[x-1] 
    value += nx
    if x-1 > 0 and line[x-2] == 1 and x < 5 and line[x] == 1:
      value += 2
    if n>1: value += search(arr[1: n], n-1, x-1)
    values.append([value, x-1])
    

  value = 0
  # 중앙
  if line[x] != 1:
    nx = line[x]
    value += nx
    if x > 0 and line[x-1] == 1 and x+1 < 5 and line[x+1] == 1:
      value += 2
    if n>1: value += search(arr[1:n], n-1, x)
    values.append([value, x])

  value = 0
  # 오
  if x < 4 and line[x+1] != 1:
    nx = line[x+1]
    value += nx
    if x+1 > 0 and line[x] == 1 and x+2 < 5 and line[x+2] == 1:
      value += 2
    if n>1: value += search(arr[1:n], n-1, x+1)
    values.append([value, x+1])

  values.sort(key = lambda x: x[0], reverse=True)
  cnt = values[0][0]
  nx = values[0][1]

  return cnt


t = int(sys.stdin.readline())

for _ in range(t):
  n = int(sys.stdin.readline())
  arr = []

  for _ in range(n):
    arr.append(list(map(int, sys.stdin.readline().split())))
  
  arr.reverse()

  sys.stdout.write(str(search(arr, n, 2)))