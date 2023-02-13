# 20924 트리의 기둥과 가지
# 시간초과

import sys
from collections import Counter
input = sys.stdin.readline

n, r = map(int, input().split())
arr = [[0 for _ in range(n+1)] for _ in range(n+1)]

for _ in range(n-1):
    a, b, d = map(int, input().split())
    arr[a][b] = d

giga = n

for i in range(1, n+1):
    c = Counter(arr[i])
    if c[0] < n - 1:
        giga = i
        break

pole = 0
branch = 0
root = 1
print(giga)
while root != giga:
    pole += arr[root][root+1]
    root += 1


q = []
q.append([giga, 0])

while q:
    cur, length = q.pop(0)
    branch = max(branch, length)

    for i in range(cur+1, n+1):
        if arr[cur][i]: q.append([i, length+arr[cur][i]])

print(pole, branch)