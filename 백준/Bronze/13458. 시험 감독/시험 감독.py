import math

n = int(input())
arr = list(map(int, input().split()))
b, c = map(int, input().split())

ans = n
for room in arr:
    p = room - b
    if p > 0:
        ans += math.ceil(p / c)

print(ans)