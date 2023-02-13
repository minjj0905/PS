import sys
input = sys.stdin.readline

n, m = map(int, input().split())
arr = [[1 for _ in range(n+1)] for _ in range(n+1)]

for _ in range(m):
    a, b = map(int, input().split())
    arr[a][b] = 0
    arr[b][a] = 0

ans = 0

for i in range(1, n+1):
    for j in range(i+1, n+1):
        for k in range(j+1, n+1):
            if arr[i][j] and arr[i][k] and arr[j][k]:
                ans += 1

print(ans)