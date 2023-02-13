import sys
input = sys.stdin.readline

n, m = map(int, input().split())
arr = [set() for _ in range(n+1)]
visit = [0 for _ in range(n+1)]
res = 0

for _ in range(m):
    a, b = map(int, input().split())
    arr[a].add(b)
    arr[b].add(a)

def bfs(x):
    q = []
    q.append(x)

    while q:
        hx = q.pop(0)

        if not visit[hx]:
            visit[hx] = 1
            for i in arr[hx]:
                q.append(i)

for i in range(1, n+1):
    if not visit[i]:
        bfs(i)
        res += 1

print(res)