import sys
input = sys.stdin.readline

n = int(input())
grid = []
for _ in range(n):
    grid.append(list(map(int, input().rstrip())))

dy = [-1, 1, 0, 0]
dx = [0, 0, -1, 1]

ans = []


def dfs(y, x, idx):
    ans[idx] += 1
    grid[y][x] = 0

    for i in range(4):
        ny = y + dy[i]
        nx = x + dx[i]

        if 0 <= ny < n and 0 <= nx < n and grid[ny][nx]:
            dfs(ny, nx, idx)


cnt = 0

for i in range(n):
    for j in range(n):
        if grid[i][j]:
            ans.append(0)
            dfs(i, j, cnt)
            cnt += 1

print(len(ans))
ans.sort()
print("\n".join(map(str, ans)))
