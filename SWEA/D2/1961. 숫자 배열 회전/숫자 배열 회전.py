t = int(input())
for tc in range(t):
    n = int(input())
    res = [['' for _ in range(n)] for _ in range(3)]
    arr = []
    for _ in range(n):
        arr.append(list(map(int, input().split())))

    for i in range(n):
        for j in range(n):
            res[0][i] += str(arr[n-1-j][i])
            res[1][i] += str(arr[n-1-i][n-1-j])
            res[2][i] += str(arr[j][n-1-i])

    print(f"#{tc+1}")

    for i in range(n):
        for j in range(3):
            print(res[j][i], end=' ')
        print()
