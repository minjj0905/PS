import sys

def search(x, y, arr, check):
  dirs = [[-1, 0], [0, 1], [1, 0], [0, -1]]
  value = 9999

  if x == 0 and y == 0:
    return 99999

  if arr[x][y] == 0:
    return 999999

  for dir in dirs:
    if (len(arr)> x+dir[0] >= 0) and (len(arr[0]) > y+dir[1] >= 0):
      if arr[x+dir[0]][y+dir[1]] == 1 and check[x+dir[0]][y+dir[1]] != 1:
        check[x+dir[0]][y+dir[1]] = 1
        value = min(search(x+dir[0], y+dir[1], arr, check), value)
      

  return value+1

t = int(sys.stdin.readline())

for i in range(t):
  n, m = map(int, sys.stdin.readline().split())
  arr = []

  for i in range(m):
    arr.append(list(map(int, sys.stdin.readline().split())))

  check = [[0 for _  in range(m)] for _ in range(n)]

  print(search(n-1, m-1, arr, check))