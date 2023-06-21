import sys
input = sys.stdin.readline

n, m = map(int, input().split())
arr = []

for _ in range(n):
    arr.append(input().rstrip())

ans = 64

for i in range(n - 8 + 1):
    for j in range(m - 8 + 1):
        cnt = 0
        for y in range(8):
            for x in range(8):
                if i+y+j+x & 1:
                    if arr[i+y][j+x] != "W":
                        cnt += 1
                else:
                    if arr[i+y][j+x] != "B":
                        cnt += 1

        ans = min(ans, cnt, 64-cnt)

print(ans)
