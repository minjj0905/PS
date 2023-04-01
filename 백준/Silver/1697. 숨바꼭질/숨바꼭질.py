import sys
from collections import deque
input = sys.stdin.readline

n, k = map(int, input().split())
visit = [0 for _ in range(100001)]
q = deque()

q.append([n, 0])
ans = 0x7fffffff
while q:
    cur, cnt = q.popleft()
    if visit[cur]:
        continue
    visit[cur] = 1
    if cnt >= ans:
        continue
    if cur == k and ans > cnt:
        ans = cnt
        continue
    if cur > 0:
        q.append([cur-1, cnt+1])
    if cur < 100000:
        q.append([cur+1, cnt+1])
    if cur <= 50000:
        q.append([cur*2, cnt+1])

print(ans)
