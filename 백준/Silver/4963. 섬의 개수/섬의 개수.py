import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**6)

dy = [-1, -1, -1, 0, 0, 1, 1, 1]
dx = [-1, 0, 1, -1, 1, -1, 0, 1]


def dfs(y, x):
    visit[y][x] = 1

    for i in range(8):
        ny = y + dy[i]
        nx = x + dx[i]

        if 0 <= ny < h and 0 <= nx < w and grid[ny][nx] and not visit[ny][nx]:
            dfs(ny, nx)


while 1:
    w, h = map(int, input().split())
    if not w:
        break

    grid = []
    visit = [[0 for _ in range(w)] for _ in range(h)]
    for _ in range(h):
        grid.append(list(map(int, input().split())))

    cnt = 0
    for i in range(h):
        for j in range(w):
            if grid[i][j] and not visit[i][j]:
                cnt += 1
                dfs(i, j)

    print(cnt)
