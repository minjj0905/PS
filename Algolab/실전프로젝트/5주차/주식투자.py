import sys
from collections import deque

tc = int(sys.stdin.readline())
for _ in range(tc):
  d = int(sys.stdin.readline())
  q = deque(list(map(int, sys.stdin.readline().split())))
  cnt = 0

  high = max(q)
  if high == q[0]:
    print(0)
    continue

  while(1):
    cur = q.popleft()
    cnt += high-cur
    if len(q) == 0:
      break
    elif cur == high:
      high = max(q)
      if high == q[0]:
        break
  
  print(cnt)