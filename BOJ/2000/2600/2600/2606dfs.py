import sys
from collections import Counter
input = sys.stdin.readline

pc = int(input())
n = int(input())
arr = [[0] * pc for _ in range(pc)]
visited = [0 for _ in range(pc)]

for _ in range(n):
    a, b = map(int, input().split())
    arr[a-1][b-1] = 1
    arr[b-1][a-1] = 1


def dfs(v):
    visited[v] = 1
    for i in range(pc):
        if arr[v][i] == 1 and visited[i] == 0:
            dfs(i)

dfs(0)
c = Counter(visited[1:])
print(c[1])