import sys
from collections import deque
input = sys.stdin.readline

n, m = map(int, input().split())
arr = [[0 for _ in range(n+1)] for _ in range(n+1)]
visit = [0 for _ in range(n+1)]
visit[1] = 1
q = deque()

for _ in range(m):
    a, b, c = map(int, input().split())
    arr[a][b] = c
    arr[b][a] = c

q.append([1, 0, visit])
ans = 0

while q:
    gym, lv, visited = q.popleft()
    if gym == n:
        ans = max(ans, lv)
        continue

    visited[gym] = 1

    for nx in range(1, n+1):
        if arr[gym][nx] and not visited[nx]:
            visited[nx] = 1
            q.append([nx, max(lv, arr[gym][nx]), visited])
            visited[nx] = 0


def isPrime(x):
    if x == 1:
        return 0

    for i in range(2, int(x**0.5) + 1):
        if not x % i:
            return 0

    return 1


while 1:
    if isPrime(ans):
        break
    ans += 1

print(ans)
