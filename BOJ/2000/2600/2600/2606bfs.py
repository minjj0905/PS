import sys
from collections import deque
input = sys.stdin.readline

pc = int(input())
n = int(input())
graph = [[] for _ in range(pc+1)]

for _ in range(n):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)

visited = [False] * (pc+1)
visited[1] = True

q = deque([1])

while q:
    x = q.popleft()
    visited[x] = True
    
    for y in graph[x]:
        if not visited[y]:
            q.append(y)
            visited[y] = True
    
print(visited[2:].count(True))