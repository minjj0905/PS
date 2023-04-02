import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**6)

n, m = map(int, input().split())
graph = [[0 for _ in range(n+1)] for _ in range(n+1)]
visit = [0 for _ in range(n+1)]
ans = 0

for _ in range(m):
    u, v = map(int, input().split())
    graph[u][v] = 1
    graph[v][u] = 1


def bfs(s, e):
    for i in range(1, n+1):
        if graph[e][i] and not visit[i]:
            visit[i] = 1
            bfs(e, i)


for i in range(1, n+1):
    for j in range(i+1, n+1):
        if graph[i][j] and not visit[i]:
            bfs(i, j)
            ans += 1

print(ans + visit.count(0) - 1)
