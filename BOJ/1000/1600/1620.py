n, m = map(int, input().split())
arr = []
d = {}
for i in range(1, n+1):
    s = input()
    d[s] = i
    arr.append(s)

for i in range(m):
    s = input()
    if s.isnumeric():
        print(arr[int(s)-1])
    else:
        print(d[s])

   