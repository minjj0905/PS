import sys

tc = int(sys.stdin.readline())
for _ in range(tc):
    n, m, d = map(int, sys.stdin.readline().split())
    arr = []
    for _ in range(m):
      arr.append(sys.stdin.readline())
    
    arr.reverse()
    cur = 2*d - 2
    for i in range(1, m):
      if 0 < (cur-1) < 2*n-2 and arr[i][cur-1] == '+':
        cur -= 2
      elif 0< (cur+1) < 2*n-2 and arr[i][cur+1] == '+':
        cur += 2
    
    sys.stdout.write(str((cur+2)//2) + '\n');