n = int(input())
arr = []
for _ in range(n):
    arr.append(int(input()))
arr.sort(reverse=True)
ans = 0

for i in range(n):
    if (x := arr[i] - i) > 0:
        ans += x
    else:
        break

print(ans)