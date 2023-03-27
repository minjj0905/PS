import sys
input = sys.stdin.readline

n, m, v = map(int, input().split())
graph = [[0 for _ in range(n+1)] for _ in range(n+1)]

for _ in range(m):
    a, b = map(int, input().split())
    graph[a][b] = 1
    graph[b][a] = 1


def dfs():
    visited = []

    def recursive(cur):
        if cur not in visited: visited.append(cur)

        for i in range(1, n+1):
            if graph[cur][i] == 1 and i not in visited:
                recursive(i)

    recursive(v)
    print(' '.join(map(str, visited)))

def bfs():
    visited = []
    queue = []
    queue.append(v)


    while(queue):
        cur = queue.pop(0)
        if cur not in visited: visited.append(cur)

        for i in range(1, n+1):
            if graph[cur][i] == 1 and i not in visited:
                queue.append(i)
     
    print(' '.join(map(str, visited)))

dfs()
bfs()