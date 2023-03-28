import sys
input = sys.stdin.readline
sys.setrecursionlimit(10000)

dy = [-1, 1, 0, 0]
dx = [0, 0, -1, 1]


def dfs(y, x):
    visit[y][x] = 1

    for i in range(4):
        ny = y + dy[i]
        nx = x + dx[i]

        if ny < 0 or nx < 0 or ny >= m or nx >= n:
            continue

        if graph[ny][nx] and not visit[ny][nx]:
            dfs(ny, nx)


t = int(input())
for i in range(t):
    n, m, k = map(int, input().split())
    graph = [[0 for _ in range(n)] for _ in range(m)]

    for _ in range(k):
        x, y = map(int, input().split())
        graph[y][x] = 1

    visit = [[0 for _ in range(n)] for _ in range(m)]

    ans = 0
    for y in range(m):
        for x in range(n):
            if graph[y][x] and not visit[y][x]:
                dfs(y, x)
                ans += 1

    print(ans)
