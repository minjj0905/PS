import sys
from collections import deque
input = sys.stdin.readline

n = int(input())
tree = [[] for _ in range(n + 1)]
par = [0 for _ in range(n+1)]

for _ in range(n-1):
    a, b = map(int, input().split())
    tree[a].append(b)
    tree[b].append(a)

q = deque()
q.append(1)

while q:
    cur = q.popleft()
    for i in tree[cur]:
        if not par[i]:
            par[i] = cur
            q.append(i)
    
for n in par[2:]:
    print(n)
