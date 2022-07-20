import sys

tc = int(sys.stdin.readline())

for i in range(tc):
  h, w, n = map(int, sys.stdin.readline().split())

  if n%h == 0:
    print(str(h) + str(n//h) if len(str(n//h)) == 2 else str(h) + "0" + str(n//h))
 
  else:
    print(str(n%h) + str(n//h+1) if len(str(n//h+1)) == 2 else str(n%h) + "0" + str(n//h+1))