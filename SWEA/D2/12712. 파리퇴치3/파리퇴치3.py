t = int(input())

for tc in range(t):
    ans = 0

    n, m = map(int, input().split())
    arr = []
    for _ in range(n):
        arr.append(list(map(int, input().split())))

    dy = [-1, 1, 0, 0]
    dx = [0, 0, -1, 1]

    ty = [-1, 1, -1, 1]
    tx = [-1, 1, 1, -1]

    for i in range(n):
        for j in range(n):
            res1, res2 = arr[i][j], arr[i][j]

            for dir in range(4):
                for k in range(1, m):
                    a = i + dy[dir] * k
                    b = j + dx[dir] * k

                    c = i + ty[dir] * k
                    d = j + tx[dir] * k

                    if -1 < a < n and -1 < b < n:
                        res1 += arr[a][b]

                    if -1 < c < n and -1 < d < n:
                        res2 += arr[c][d]

            ans = max(ans, res1, res2)

    print(f"#{tc+1} {ans}")
