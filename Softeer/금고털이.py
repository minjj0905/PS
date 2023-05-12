import sys
input = sys.stdin.readline

w, n = map(int, input().split())
arr = []
for _ in range(n):
    arr.append(list(map(int, input().split())))

arr.sort(key=lambda x: x[1], reverse=True)

ans = 0

for m, p in arr:
    if w > m:
        ans += m*p
        w -= m
    else:
        ans += w*p
        break

print(ans)
