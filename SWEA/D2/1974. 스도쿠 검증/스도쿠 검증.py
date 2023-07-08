t = int(input())
for tc in range(t):
    ans = 1

    grid = []
    for _ in range(9):
        grid.append(list(map(int, input().split())))

    for i in range(9):
        if len(set(grid[i])) != 9:
            ans = 0
            break

        if len(set([j[i] for j in grid])) != 9:
            ans = 0
            break

        s = set()
        col = i % 3
        row = i // 3
        for j in range(3):
            s.update(grid[row*3 + j][col*3: (col+1) * 3])

        if len(s) != 9:
            ans = 0
            break

    print(f"#{tc+1} {ans}")
