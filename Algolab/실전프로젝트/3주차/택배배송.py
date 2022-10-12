import sys
from collections import deque

def search(k):
    queue = deque([start_node])
    visit = [False] * (n+1)
    visit[start_node] = True
    while queue:
        x = queue.popleft()
        for y, weight in a_list[x]:
            if not visit[y] and weight >= k:
                visit[y] = True
                queue.append(y)
    return visit[end_node]

tc = int(sys.stdin.readline())
for _ in range(tc):
  n, m, start_node, end_node = map(int, sys.stdin.readline().split())

  a_list = [[] for _ in range(n+1)]
  start = 1000000000
  end = 1
  for _ in range(m): 
    a, b, c = map(int, sys.stdin.readline().split())
    a_list[a].append((b, c))
    a_list[b].append((a, c))
    start = min(start, c)
    end = max(end, c)

  res = start
  while start <= end:
    mid = (start + end) // 2
    if search(mid):
        res = mid
        start = mid + 1
    else:
        end = mid - 1

  sys.stdout.write(str(res) + '\n')
