import sys
from collections import deque

t = int(sys.stdin.readline())

for i in range(t):
  n, m = map(int, input().split())
  graph = []

  for _ in range(n):
      graph.append(list(map(int, list(input()))))

  queue = deque()
  queue.append((0, 0))

  dy = [1, 0, -1, 0]
  dx = [0, 1, 0, -1]

  while queue:
      y, x = queue.popleft()

      for i in range(4):
          nx = x + dx[i]
          ny = y + dy[i]

          if 0 <= ny < n and 0 <= nx < m and graph[ny][nx]:
              if graph[ny][nx] == 1:
                  graph[ny][nx] = graph[y][x] + 1
                  queue.append((ny, nx))

              elif graph[ny][nx] > graph[y][x] + 1:
                  graph[ny][nx] = graph[y][x] + 1
                  queue.append((ny, nx))

  print(graph[n-1][m-1])