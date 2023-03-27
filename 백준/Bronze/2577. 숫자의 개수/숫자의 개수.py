arr = []
for i in range(3):
  arr.append(int(input()))

res = str(arr[0] * arr[1] * arr[2])
ans = [0 for _ in range(10)]

for c in res:
  ans[int(c)] += 1

for n in ans:
  print(n)
