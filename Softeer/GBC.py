import sys
input = sys.stdin.readline

n, m = map(int, input().split())
arr = [0]

ans = 0

for i in range(n):
    d, s = map(int, input().split())
    arr += [s] * d

cur = 1
for i in range(m):
    dis, speed = map(int, input().split())
    for j in range(cur, cur + dis):
        ans = max(ans, speed-arr[j])
    cur += dis

print(ans)
