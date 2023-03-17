import sys
from collections import deque
input = sys.stdin.readline

n, m = map(int, input().split())

graph = [[0 for _ in range(n+1)] for _ in range(n+1)]
indegree = [0 for _ in range(n+1)]
res = [987654321 for _ in range(n+1)]

for _ in range(m):
    a, b = map(int, input().split())
    graph[b][a] = 1
    indegree[b] += 1

q = deque();
for i in range(1, n+1):
    if not indegree[i]: q.append([i, 1])

while q:
    sub, cnt = q.popleft()
    if cnt >= res[sub]: continue

    res[sub] = cnt
    
    for i in range(1, n+1):
        if graph[i][sub]: indegree[i] -=1
    
    for i in range(1, n+1):
        if not indegree[i]: q.append([i, cnt+1])


print(*res[1:])