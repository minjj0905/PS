import sys
 
t = int(sys.stdin.readline())

for i in range(t):
  n, d = map(int, sys.stdin.readline().split())
  arr = list(set(map(int, sys.stdin.readline().split())))
  
  doll = arr[0]
  cnt = 1
  
  for i in range(1, len(arr)):
    if(doll+d <= arr[i]):
      cnt += 1;
      doll = arr[i]

  print(cnt)
