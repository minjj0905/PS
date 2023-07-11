from collections import deque

n = int(input())
m = int(input())
arr = [[] for _ in range(n+1)]

for _ in range(m):
    a, b = map(int, input().split())
    arr[a].append(b)
    arr[b].append(a)

invite = []

q = deque()
for i in arr[1]:
    q.append([i, 1])

while q:
    friend, cnt = q.popleft()
    if friend == 1 or friend in invite: continue

    if cnt <= 2: invite.append(friend)

    for nx in arr[friend]:
        if nx not in invite and cnt < 2:
            q.append([nx, cnt+1])

print(len(invite))
