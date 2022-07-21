import sys

n = int(sys.stdin.readline())
arr = []

for i in range(n):
  age, name = sys.stdin.readline().split()
  arr.append([int(age), name])

arr.sort(key= lambda x : x[0])

for i in range(n):
  print(arr[i][0], arr[i][1])